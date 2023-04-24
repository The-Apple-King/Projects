#include <stdio.h>
#include <string.h>
#include "connection_queue.h"

int connection_queue_init(connection_queue_t *queue) {
    // TODO Not yet implemented
    queue = malloc(sizeof(connection_queue_t));
    if(queue == NULL){
        perror("malloc");
        return -1;
    }
    queue->length = 0;
    queue->read_idx = 0;
    queue->write_idx = 0;
    return 0;
}

int connection_enqueue(connection_queue_t *queue, int connection_fd) {
    // TODO Not yet implemented
    if(queue->length < 5){
        queue->length++;
        queue->client_fds[length] = connection_fd;
    }
    return 0;
}

int connection_dequeue(connection_queue_t *queue) {
    // TODO Not yet implemented
    
    return 0;
}

int connection_queue_shutdown(connection_queue_t *queue) {
    // TODO Not yet implemented
    return 0;
}

int connection_queue_free(connection_queue_t *queue) {
    // TODO Not yet implemented
    if(free(queue) == -1){
        return -1;
    }
    return 0;
}
