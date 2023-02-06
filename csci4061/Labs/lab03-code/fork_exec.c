#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int child_status = -1;

    // TODO Fork a child process to run the command "cat sample.txt"
    // The parent should wait and print out the child's exit code

    printf("Child exited with status %d\n", child_status);
    return 0;
}
