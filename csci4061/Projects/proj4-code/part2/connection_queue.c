#include <stdio.h>
#include <string.h>
#include "connection_queue.h"


int connection_queue_init(connection_queue_t *queue) {
    // TODO Not yet implemented
    queue->length = 0;
    queue->read_idx = 0;
    queue->write_idx = 0;
    queue->shutdown = 0;

    if (pthread_mutex_init(&queue->lock, NULL)!= 0){
        perror("mutex init");
        return -1;
    }
    if (pthread_cond_init(&queue->queue_full, NULL)!= 0){
        perror("cond init");
        pthread_mutex_destroy(&queue->lock);
        return -1;
    }
    if (pthread_cond_init(&queue->queue_empty, NULL)!= 0){
        perror("cond init");
        pthread_mutex_destroy(&queue->lock);
        pthread_cond_destroy(&queue->queue_full);
        return -1;
    }
    return 0;
}

int connection_enqueue(connection_queue_t *queue, int connection_fd) {
    //lock thread
    if (pthread_mutex_lock(&queue->lock) != 0){
        perror("mutex lock");
        return -1;
    }
    while(queue->length == 5){
        if (pthread_cond_wait(&queue->queue_full, &queue->lock) != 0){
            perror("cond wait");
            pthread_mutex_unlock(&queue->lock);
            return -1;
        }
    }
    // put a test for shutdown flag
    if (queue->shutdown)
    {
        pthread_mutex_unlock(&queue->lock);
        return -1;
    }

    // write a file descriptor here
    queue->client_fds[queue->write_idx] = connection_fd; // add new val to queue
    queue->length++;    // increment length to reflect adding val
    queue->write_idx++; // increment index because something was just added
    queue->write_idx %= 5; // make sure index loops

    if (pthread_cond_signal(&queue->queue_empty) != 0){
        perror("cond signal");
        pthread_mutex_unlock(&queue->lock);
        return -1;
    }
    if (pthread_mutex_unlock(&queue->lock) != 0){
        perror("cond signal");
        return -1;
    }
    return 0;
}

int connection_dequeue(connection_queue_t *queue) {
    if (pthread_mutex_lock(&queue->lock) != 0){
        perror("mutex lock");
        return -1;
    }
    while(queue->length == 0){
        if (pthread_cond_wait(&queue->queue_empty, &queue->lock) != 0){
            perror("cond wait");
            pthread_mutex_unlock(&queue->lock);
            return -1;
        }
    }

    // put a test for shutdown flag
    if (queue->shutdown)
    {
        pthread_mutex_unlock(&queue->lock);
        return -1;
    }

    int output = queue->client_fds[queue->read_idx]; // save file descriptor to loc
    queue->length--;    // change length to reflect removing data
    queue->read_idx++;  // increment read index
    queue->read_idx %= 5;  // make sure read index loops back to 0

    if (pthread_cond_signal(&queue->queue_full) != 0){
        perror("cond signal");
        pthread_mutex_unlock(&queue->lock);
        return -1;
    }
    if (pthread_mutex_unlock(&queue->lock) != 0){
        perror("mutex unlock");
        return -1;
    }
    return output;
}

int connection_queue_shutdown(connection_queue_t *queue) {
    queue->shutdown = 1;

    // Signal any waiting threads that the queue is being shut down
    if (pthread_cond_broadcast(&queue->queue_empty) != 0){
        perror("cond broadcast");
        return -1;
    }
    if (pthread_cond_broadcast(&queue->queue_full) != 0){
        perror("cond broadcast");
        return -1;
    }

    return 0;
}

int connection_queue_free(connection_queue_t *queue) {

    if (pthread_mutex_destroy(&queue->lock) != 0){
        perror("mutex destroy");
        return -1;
    }
    if (pthread_cond_destroy(&queue->queue_full) != 0){
        perror("cond destroy");
        return -1;
    }
    if (pthread_cond_destroy(&queue->queue_empty) != 0){
        perror("cond destroy");
        return -1;
    }
    return 0;
}
