#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_WORD_LEN 25

/*
 * Counts the number of occurrences of words of different lengths in a text
 * file and stores the results in an array.
 * file_name: The name of the text file from which to read words
 * counts: An array of integers storing the number of words of each possible
 *     length.  counts[0] is the number of 1-character words, counts [1] is the
 *     number of 2-character words, and so on.
 * Returns 0 on success or -1 on error.
 */
int count_word_lengths(const char *file_name, int *counts) {
  FILE *fd = fopen(file_name, "r");
  if (fd == NULL) {
    perror("fopen");
    return -1;
  }
  char test = 'a';
  int count = 0;

  // test if test is a letter if so count ++ when its a whitespace update counts
  // and set count to 0
  while (fread(&test, sizeof(char), 1, fd) == 1) {
    if (isalpha(test)) {
      count++;
    } else if (isspace(test)) {
      counts[count - 1]++;
      count = 0;
    }
  }

  if (ferror(fd)) {
    perror("fread");
    fclose(fd);
    return -1;
  }

  fclose(fd);
  return 0;
}

/*
 * Processes a particular file (counting the number of words of each length)
 * and writes the results to a file descriptor.
 * This function should be called in child processes.
 * file_name: The name of the file to analyze.
 * out_fd: The file descriptor to which results are written
 * Returns 0 on success or -1 on error
 */
int process_file(const char *file_name, int out_fd) {
  // create arr and set every val to 0
  int counts[MAX_WORD_LEN];
  memset(counts, 0, sizeof(counts));

  // call this function
  count_word_lengths(file_name, counts);

  if (write(out_fd, counts, sizeof(int) * MAX_WORD_LEN) == -1) {
    perror("write");
    return -1;
  }

  return 0;
}

int main(int argc, char **argv) {
  if (argc == 1) {
    // No files to consume, return immediately
    return 0;
  }
  // TODO Create a pipe for child processes to write their results
  int fd[2];
  pipe(fd);

  // TODO Fork a child to analyze each specified file (names are argv[1],
  // argv[2], ...)
  // child handling
  for (size_t i = 0; i < argc - 1; i++) {
    pid_t child_pid = fork();
    if (child_pid == 0) {
      close(fd[0]);
      process_file(argv[i + 1], fd[1]);
      exit(0);
    }
  }
  // parent handling
  close(fd[1]);
  int status;
  for (size_t i = 0; i < argc - 1; i++) {
    wait(&status);
    if (WEXITSTATUS(status) != 0) {
      close(fd[0]);
      return -1;
    }
  }

  // TODO Aggregate all the results together by reading from the pipe in the
  // parent
  int counts[MAX_WORD_LEN];
  memset(counts, 0, sizeof(counts));
  int current;
  for (size_t i = 0; i < argc - 1; i++) {
    for (size_t j = 0; j < MAX_WORD_LEN; j++) {
      if(read(fd[0], &current, sizeof(int)) == -1){
        perror("read");
        return -1;
      }
      counts[j] += current;
    }
  }

  // TODO Change this code to print out the total count of words of each length
  for (int i = 1; i <= MAX_WORD_LEN; i++) {
    printf("%d-Character Words: %d\n", i, counts[i-1]);
  }
  return 0;
}
