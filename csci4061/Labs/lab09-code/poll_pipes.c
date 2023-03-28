#include <stdio.h>
#include <stdlib.h>
#include <sys/poll.h>
#include <sys/wait.h>
#include <unistd.h>

#define NUM_CHILDREN 7
#define RAND_SEED 4061

int main() {
  int child_values[] = {4, 8, 15, 16, 23, 42, 108};
  srand(RAND_SEED);

  // Create a pipe for each child process
  int pipe_fds[2 * NUM_CHILDREN];
  for (int i = 0; i < NUM_CHILDREN; i++) {
    if (pipe(pipe_fds + 2 * i) == -1) {
      perror("pipe");
      for (int j = 0; j < 2 * i; j++) {
        close(pipe_fds[j]);
      }
      return 1;
    }
  }

  // Launch child processes, each writing to pipe after random delay
  for (int i = 0; i < NUM_CHILDREN; i++) {
    int delay = rand() % 13;

    pid_t child_pid = fork();
    if (child_pid == -1) {
      perror("fork");
      for (int j = 0; j < 2 * NUM_CHILDREN; j++) {
        close(pipe_fds[j]);
      }
      return 1;
    }

    else if (child_pid == 0) {
      sleep(delay);

      int ret_val = 0;
      if (write(pipe_fds[2 * i + 1], child_values + i, sizeof(int)) == -1) {
        perror("write");
        ret_val = 1;
      }
      for (int j = 0; j < 2 * NUM_CHILDREN; j++) {
        if (close(pipe_fds[j]) == -1) {
          ret_val = 1;
        }
      }
      return ret_val;
    }
  }

  // TODO Change this code to read from pipes as soon as data is available
  // Use the poll() system call

  // create a counter for the number of children to process
  int remaining_children = NUM_CHILDREN;

  // set up the poll struct
  struct pollfd *fds = malloc(NUM_CHILDREN * sizeof(struct pollfd));
  // set up the read ends of the pipe
  for (int i = 0; i < NUM_CHILDREN; i++) {
    fds[i].fd = pipe_fds[2 * i];  // Monitor read end of pipe
    fds[i].events = POLLIN;       // Check for read
  }

  // keep running until we finish all children
  while (remaining_children > 0) {
    // if a child ends we loop through them all and read what we need
    if (poll(fds, NUM_CHILDREN, -1) > 0) {
      for (int i = 0; i < NUM_CHILDREN; i++) {
        // check which pipe is ready
        if (fds[i].revents & POLLIN) {
          // process pipe
          int result;
          if (read(pipe_fds[2 * i], &result, sizeof(int)) == -1) {
            perror("read");
            for (int j = 0; j < 2 * NUM_CHILDREN; j++) {
              close(pipe_fds[j]);
            }
            return 1;
          }
          printf("Child %d Result: %d\n", i, result);
        }
      }
    }
    remaining_children--;  // if we get here we finished a child process
  }
  free(fds);  // free data
  // End TODO block

  int ret_val = 0;
  for (int i = 0; i < 2 * NUM_CHILDREN; i++) {
    if (close(pipe_fds[i]) == -1) {
      ret_val = 1;
    }
  }
  // Wait for all children -- not strictly necessary but good practice
  for (int i = 0; i < NUM_CHILDREN; i++) {
    if (wait(NULL) == -1) {
      perror("wait");
      ret_val = 1;
    }
  }
  return ret_val;
}
