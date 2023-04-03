#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define DEPT_LEN 5
#define NAME_LEN 128

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <Department> <Number>\n", argv[0]);
        return 1;
    }
    // You may uncomment the following lines if you would like to use them
    // const char *department = argv[1];
    // int number = atoi(argv[2]);

    // TODO Send a request for a course's title to UDP server
    // You will need to use getaddrinfo() first
    // Followed by the socket() system call
    // And finally sendto() to send a request and recvfrom() to get the reply

    // Pay close attention to the request/response formats explained in
    // QUESTIONS.txt -- you are encouraged to use structs to represent
    // requests and responses
    //
    // Don't forget about endianness!
}
