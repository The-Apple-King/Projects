#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include "http.h"

#define BUFSIZE 512

const char *get_mime_type(const char *file_extension) {
    if (strcmp(".txt", file_extension) == 0) {
        return "text/plain";
    } else if (strcmp(".html", file_extension) == 0) {
        return "text/html";
    } else if (strcmp(".jpg", file_extension) == 0) {
        return "image/jpeg";
    } else if (strcmp(".png", file_extension) == 0) {
        return "image/png";
    } else if (strcmp(".pdf", file_extension) == 0) {
        return "application/pdf";
    }

    return NULL;
}

int read_http_request(int fd, char *resource_name) {
    char buf[BUFSIZE];
    if(read(fd, buf, BUFSIZE) == -1){
        perror("read");
        return -1;
    }

    
    char* first_word = strtok(buf, " "); // get the first word
    char* second_word = strtok(NULL, " "); // get the second word
    
    if (first_word == NULL || second_word == NULL) {
        perror("bad HTTP request");
        return -1;
    }
    
    strcpy(resource_name, second_word);
    
    return 0;
}


int write_http_response(int fd, const char *resource_path) {
    char buf[BUFSIZE];
    struct stat st;
    int read_bytes, sent_bytes, remaining_bytes;
    FILE *resource_file;

    // Check if the file exists
    if (stat(resource_path, &st) == -1) {
        // File not found
        if (errno == ENOENT) {
            sprintf(buf, "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n");
            write(fd, buf, strlen(buf));
            return 0;
        }
        // Other error
        perror("stat");
        return -1;
    }

    // Open the file for reading
    resource_file = fopen(resource_path, "r");
    if (resource_file == NULL) {
        perror("fopen");
        return -1;
    }

    // Send 200 OK response headers
    sprintf(buf, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\nContent-Type: %s\r\n\r\n", st.st_size, get_mime_type(resource_path));
    write(fd, buf, strlen(buf));

    // Send the file contents
    remaining_bytes = st.st_size;
    while (remaining_bytes > 0) {
        read_bytes = fread(buf, 1, BUFSIZE, resource_file);
        if (read_bytes == 0) {
            if (feof(resource_file)) {
                break; // End of file
            }
            perror("fread");
            fclose(resource_file);
            return -1;
        }
        sent_bytes = write(fd, buf, read_bytes);
        if (sent_bytes < 0) {
            perror("write");
            fclose(resource_file);
            return -1;
        }
        remaining_bytes -= sent_bytes;
    }

    // Close the file
    fclose(resource_file);

    return 0;
}

