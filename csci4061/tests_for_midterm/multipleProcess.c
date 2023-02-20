#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{

    pid_t pid = fork();

    if (pid == 0)
    {
        printf("doing child process\n doing stuff early\n");
        execlp("ls", "ls", NULL);
        printf("this is after a list command");
        //execlp("cp", "~/out1.txt", "~/out1Copy.txt", NULL);
    }
    else
    {
        int exitPID = waitpid(pid, 0, 0);
        printf("parent process child exit:%d", exitPID);
    }

    return 0;
}