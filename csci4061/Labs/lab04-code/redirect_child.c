// redirect_child.c: starts a child process which will print into a
// file instead of onto the screen. Uses dup2(), fork(), and wait()

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    { // check for at least 1 command line arg
        printf("Usage: %s <childfile>\n", argv[0]);
        return 1;
    }

    // Uncomment lines below to use specified output file and command-line args in child process
    char *output_file = argv[1];                                        // output file that child process will print into
    char *child_argv[] = {"wc", "test_cases/resources/nums.txt", NULL}; // child command/arguments to execute;

    // TODO: Spawn a child process, which will exec the "wc" command with the arguments in 'child_argv'
    // Redirect the output of the command to 'output_file'

    pid_t pid = fork();

    // if error
    if (pid < 0)
    {
        // An error occurred
        perror("fork() failed");
        return 1;
    }
    // if this is a child
    else if (pid == 0)
    {
        int file = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        if (file == -1)
        { // check for errors opening file
            perror("Couldn't open file 'out.txt'");
            return 1; // Bail out if open fails
        }

        int fileOut = dup2(file, STDOUT_FILENO);
        if (fileOut == -1)
        { // check for errors opening file
            perror("Couldn't update output");
            return 1; // Bail out if open fails
        }

        execlp(child_argv[0], child_argv[0], child_argv[1], NULL);
        return 0;
    }
    // if parent
    else
    {
        int returnStat = 0;
        waitpid(pid, &returnStat, 0);
        returnStat = WEXITSTATUS(0);
        printf("Child complete, return code %d\n", WEXITSTATUS(returnStat));
        return 0;
    }

    // TODO: In the parent, wait for the child and ensure it terminated normally using wait macros
    // Print "Child complete, return code <status_code>" if child terminated normally, replacing
    //    <status_code> with the child's numerical status code
    // Print "Child exited abnormally" if child terminated abnormally

    return 0;
}
