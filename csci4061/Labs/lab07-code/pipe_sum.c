#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int write_sums_to_pipe(const char *file_name, int pipe_write_fd) {
    FILE *f = fopen(file_name, "r");
    if (f == NULL) {
        perror("fopen");
        return 1;
    }

    int sum = 0;
    int n;
    while (fscanf(f, "%d", &n) > 0) {
        sum += n;
        // TODO write cumulative sum to pipe
        write(pipe_write_fd, &sum, sizeof(sum));
    }

    int ret_val = 0;
    if (ferror(f)) {
        perror("Failed to read file");
        ret_val = 1;
    }
    fclose(f);
    return ret_val;
}

int read_sums_from_pipe(int pipe_read_fd) {
    // TODO read all sums from pipe
    int temp = 0;
    while(read(pipe_read_fd, &temp, sizeof(temp))){
        printf("Cumulative Sum: %d\n", temp);
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <numbers_file>\n", argv[0]);
        return 1;
    }
    // Uncomment line below if you would like to use it
    // const char *file_name = argv[1];

    // TODO set up pipe file descriptors
    int fd[2]; // [0] for read [1] for write
    pipe(fd);

    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        return 1;
    }

    else if (child_pid == 0) {
        // TODO write code to do the following:
        // 1. Close unused pipe file descriptors
        close(fd[0]);
        // 2. Call 'write_sums_to_pipe' with appropriate arguments
        write_sums_to_pipe(argv[1], fd[1]);
        // 3. Close remaining pipe file descriptors
        close(fd[1]);
    }

    else {
        // TODO write code to do the following:
        // 1. Close unused pipe file descriptors
        close(fd[1]);
        // 2. Call 'read_sums_from_pipe' with appropriate arguments
        read_sums_from_pipe(fd[0]);
        // 3. Close remaining pipe file descriptors
        close(fd[0]);
    }

    return 0;
}
