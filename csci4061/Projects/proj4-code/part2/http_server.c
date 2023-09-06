#include <errno.h>
#include <netdb.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include "connection_queue.h"
#include "http.h"

#define BUFSIZE 512
#define LISTEN_QUEUE_LEN 5
#define N_THREADS 5

int keep_going = 1;
const char *serve_dir;

void handle_sigint(int signo) {
    keep_going = 0;
}

void *handle_requests(void* queue){
    while (keep_going)
    {
    // read relative address and write to buf
        char buf[BUFSIZE];
        int client_sockfd = connection_dequeue(queue);
        if(client_sockfd == -1){
            // connection_dequeue returns -1 when we shutdown
            break;
        }
        if(read_http_request(client_sockfd, buf) == -1){
            perror("read");
            close(client_sockfd);
            pthread_exit(NULL);
        }

        // save full path to full_path
        char full_path[BUFSIZE];
        if(snprintf(full_path, BUFSIZE, "%s%s", serve_dir, buf) < 0){
            perror("snprintf");
            close(client_sockfd);
            pthread_exit(NULL);
        }

        //write request
        if(write_http_response(client_sockfd, full_path) == -1){
            perror("write_http_response");
            close(client_sockfd);
            pthread_exit(NULL);
        }

        if(close(client_sockfd) == -1){
            perror("close");
            close(client_sockfd);
            pthread_exit(NULL);
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    // First command is directory to serve, second command is port
    if (argc != 3) {
        printf("Usage: %s <directory> <port>\n", argv[0]);
        return 1;
    }
    // Uncomment the lines below to use these definitions:
    serve_dir = argv[1];
    const char *port = argv[2];

    //create queue
    connection_queue_t queue;
    if(connection_queue_init(&queue) == -1){
        perror("queue init");
        return -1;
    }

    // setup sig handler
    struct sigaction sa;
    sa.sa_handler = handle_sigint;
    if(sigemptyset(&sa.sa_mask) != 0){
        perror("sigemptyset");
        connection_queue_shutdown(&queue);
        connection_queue_free(&queue);
        return -1;
    }
    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        connection_queue_shutdown(&queue);
        connection_queue_free(&queue);
        return -1;
    }

    //create getaddrinfo stuff
    struct addrinfo hints, *res;
    if(memset(&hints, 0, sizeof(hints)) == NULL){
        perror("memset");
        connection_queue_shutdown(&queue);
        connection_queue_free(&queue);
        return -1;
    }
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    int status = getaddrinfo(NULL, port, &hints, &res);
    if (status != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        connection_queue_shutdown(&queue);
        connection_queue_free(&queue);
        return -1;
    }
    
    //set up socket
    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if(sockfd == -1){
        perror("socket");
        freeaddrinfo(res);
        connection_queue_shutdown(&queue);
        connection_queue_free(&queue);
        return -1;
    }

    // bind the socket to a local address and port
    if(bind(sockfd, res->ai_addr, res->ai_addrlen) == -1){
        perror("bind");
        close(sockfd);
        freeaddrinfo(res);
        connection_queue_shutdown(&queue);
        connection_queue_free(&queue);
        return -1;
    }
    
    //we never use res after this
    if (res != NULL) {
        freeaddrinfo(res);
    } else {
        fprintf(stderr, "res is NULL\n");
    }

    //listen for connect requests, Max reasonable num for backlog
    if(listen(sockfd, SOMAXCONN) == -1){
        perror("listen");
        close(sockfd);
        connection_queue_shutdown(&queue);
        connection_queue_free(&queue);
        return -1;
    }

    // set mask for threads
    sigset_t new_mask, old_mask;
    if(sigfillset(&new_mask) != 0){
        perror("sigfillset");
        close(sockfd);
        connection_queue_shutdown(&queue);
        connection_queue_free(&queue);
        return -1;
    }
    if(sigprocmask(SIG_SETMASK, &new_mask, &old_mask) != 0){
        perror("set mask for threads");
        close(sockfd);
        connection_queue_shutdown(&queue);
        connection_queue_free(&queue);
        return -1;
    }


    //create threads
    pthread_t threads[N_THREADS];
    for (size_t i = 0; i < N_THREADS; i++)
    {
        int error = 0;
        error = pthread_create(&threads[i], NULL, handle_requests, (void*)&queue);
        if (error != 0){
            fprintf(stderr, "pthread_create: %s\n", strerror(error));
            close(sockfd);
            connection_queue_shutdown(&queue);
            connection_queue_free(&queue);
            return -1;
        }
    }
    
    // restore old mask
    if(sigprocmask(SIG_SETMASK, &old_mask, NULL) != 0){
        perror("restore sigmask");
        close(sockfd);
        connection_queue_shutdown(&queue);
        connection_queue_free(&queue);
        return -1;
    }


    while (keep_going)
    {
        // accept a new client connection
        struct sockaddr_storage client_addr;
        socklen_t client_addrlen = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addrlen);
        if (client_sockfd == -1 && errno != EINTR) {
            perror("accept");
            close(sockfd);
            connection_queue_shutdown(&queue);
            connection_queue_free(&queue);
            return -1;
        }

        // add file descriptor for socket to queue
        if(connection_enqueue(&queue, client_sockfd) == -1){
            perror("enqueue");
            close(sockfd);
            connection_queue_shutdown(&queue);
            connection_queue_free(&queue);
            return -1;
        }
    }
    if(connection_queue_shutdown(&queue) == -1){
        perror("shutdown");
        close(sockfd);
        connection_queue_shutdown(&queue);
        connection_queue_free(&queue);
        return -1;
    }
    
    // wait for threads to finish
    for (size_t i = 0; i < N_THREADS; i++)
    {
        int error = 0;
        error = pthread_join(threads[i], NULL);
        if (error != 0){
            fprintf(stderr, "pthread_create: %s\n", strerror(error));
            close(sockfd);
            connection_queue_free(&queue);
            return -1;
        }
    }

    // start closing server down
    if (close(sockfd) == -1) {
      perror("close");
      connection_queue_free(&queue);
    }

    //free queue
    if(connection_queue_free(&queue) == -1){
        perror("queue free");
        return -1;
    }

    return 0;
}
