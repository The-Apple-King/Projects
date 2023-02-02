#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int child_status = -1;

    // TODO Fork a child process to run the command "cat sample.txt"
    // The parent should wait and print out the child's exit code
    pid_t pid = fork();

    if (pid == 0) // if child
    {
        execlp("/usr/bin/cat", "cat", "/mnt/c/Users/gifte/Documents/projects/csci4061/Labs/lab03-code/sample.txt", NULL);
    }
    else
    {
        waitpid(0, WEXITSTATUS(1), WUNTRACED);
        child_status = WEXITSTATUS(0);
        printf("Child exited with status %d\n", child_status);
        
    }
    return 0;
}
