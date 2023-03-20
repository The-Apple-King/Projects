#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    // Run equivalent of the command pipeline 'sort -n test_cases/resources/numbers.txt | tail -n 10'

    // TODO Create pipe
    int pipeline[2];
    pipe(pipeline);

    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        // TODO Insert any necessary cleanup
        close(pipeline[0]);
        close(pipeline[1]);

        return 1;
    } else if (child_pid == 0) {
        // TODO Close write end of pipe
        close(pipeline[1]);

        // TODO Run the 'tail' command, setting up input from pipe first
        
        if (dup2(pipeline[0], STDIN_FILENO) == -1)
        {
            perror("dup2 in child");
        }
        if(execlp("tail", "tail", "-n", "10", NULL) == -1){
            perror("tail command error");
        }

        return 0; // Not reached on successful exec()
    } else {
        // TODO Parent closes read end of pipe
        close(pipeline[0]);
    }

    // TODO Run 'sort' command in original process, setting up output to pipe first
    if (dup2(pipeline[1], STDOUT_FILENO) == -1)
        {
            perror("dup2 in main");
        }
    if(execlp("sort", "sort", "-n", "test_cases/resources/numbers.txt", NULL) == -1){
        perror("sort command not working");
    }

    return 0; // Not reached on successful exec()
}
