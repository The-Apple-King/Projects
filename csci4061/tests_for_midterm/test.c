#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

    int part1(){
    // part 1
    int fd = open("out1.txt", O_CREAT | O_TRUNC | O_WRONLY,
                  S_IRUSR | S_IWUSR);
    char *message1 = "Hello 4061";
    char *message2 = "World 4061";
    fork();
    write(fd, message1, strlen(message1));
    close(fd);
    return 0;
    }

    int part2(){
    // part 2
    int fd = open("out2.txt", O_CREAT | O_TRUNC | O_WRONLY,
                  S_IRUSR | S_IWUSR);
    char *message1 = "Hello 4061";
    char *message2 = "World 4061";
    pid_t child_pid = fork();
    if (child_pid == 0)
    {
        write(fd, message1, strlen(message1));
    }
    else
    {
        write(fd, message2, strlen(message2));
    }
    close(fd);
    return 0;
    }

    int part3(){
    // part 3
    int fd = open("out3.txt", O_CREAT | O_TRUNC | O_WRONLY,
                  S_IRUSR | S_IWUSR);
    char *message1 = "Hello 4061";
    char *message2 = "World 4061";
    pid_t child_pid = fork();
    if (child_pid == 0)
    {
        write(fd, message1, strlen(message1));
    }
    else
    {
        wait(NULL);
        write(fd, message2, strlen(message2));
    }
    close(fd);
    return 0;
    }

int part4(){
    // part 4
    int fd = open("out4.txt", O_CREAT | O_TRUNC | O_WRONLY,
                  S_IRUSR | S_IWUSR);
    char *message1 = "Hello 4061";
    char *message2 = "World 4061";
    pid_t child_pid = fork();
    if (child_pid == 0)
    {
        write(fd, message1, strlen(message1));
    }
    else
    {
        write(fd, message2, strlen(message2));
        wait(NULL);
    }
    close(fd);
    return 0;
}

int part5(){
    // part 5
    int fd = open("out5.txt", O_CREAT | O_TRUNC | O_WRONLY,
                  S_IRUSR | S_IWUSR);
    char *message1 = "Hello 4061";
    char *message2 = "World 4061";
    pid_t child_pid = fork();
    if (child_pid == 0)
    {
        execlp("ls", "ls", NULL);
        write(fd, message1, strlen(message1));
    }
    else
    {
        write(fd, message2, strlen(message2));
    }
    close(fd);
    return 0;
}



int main()
{
    part1();
    part2();
    part3();
    part4();
    part5();
    return 0;
}