#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define DEPT_LEN 5
#define NAME_LEN 128

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s <Department> <Number>\n", argv[0]);
    return 1;
  }
  // You may uncomment the following lines if you would like to use them
  struct request {
    char department[5];
    int number;
  };

  struct response {
    int lookUpStatus;
    char courseName[128];
  };

  struct request rq;
  memcpy(rq.department, argv[1], sizeof(char) * 5);
  rq.number = atoi(argv[2]);
  rq.number = htonl(rq.number);

  struct response res;

  // TODO Send a request for a course's title to UDP server
  // You will need to use getaddrinfo() first
  struct addrinfo hints;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_DGRAM;
  struct addrinfo *server;

  // set up addr info for socket
  int ret_val = getaddrinfo("23.23.63.223", "4061", &hints, &server);
  if (ret_val != 0) {
    fprintf(stderr, "getaddrinfo failed: %s\n", gai_strerror(ret_val));
    return 1;
  }

  // Followed by the socket() system call
  int sock_fd =
      socket(server->ai_family, server->ai_socktype, server->ai_protocol);
  if (sock_fd == -1) {
    perror("socket");
    freeaddrinfo(server);
    return 1;
  }


  // And finally sendto() to send a request and recvfrom() to get the reply
  if (sendto(sock_fd, &rq, sizeof(struct request), 0, server->ai_addr,
             server->ai_addrlen) == -1) {
    perror("sendto");
    freeaddrinfo(server);
    close(sock_fd);
    return 1;
  }

  // recvfrom
  if (recvfrom(sock_fd, &res, sizeof(struct response), 0, NULL, NULL) == -1) {
    perror("recvfrom");
    close(sock_fd);
    freeaddrinfo(server);
    return 1;
  }
    res.lookUpStatus = htonl(res.lookUpStatus);

  if (res.lookUpStatus == -1) {
    printf("Course Not Found\n");
    close(sock_fd);
    freeaddrinfo(server);
    return 1;
  }

  printf("Course Title: %s\n", res.courseName);

  freeaddrinfo(server);
  if (close(sock_fd) == -1) {
    perror("close");
    return 1;
  }

  // Pay close attention to the request/response formats explained in
  // QUESTIONS.txt -- you are encouraged to use structs to represent
  // requests and responses
  //
  // Don't forget about endianness!
  return 0;
}
