#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "string_vector.h"
#include "swish_funcs.h"

#define MAX_ARGS 10

/*
 * Helper function to run a single command within a pipeline. You should make
 * make use of the provided 'run_command' function here.
 * tokens: String vector containing the tokens representing the command to be
 * executed, possible redirection, and the command's arguments.
 * pipes: An array of pipe file descriptors.
 * n_pipes: Length of the 'pipes' array
 * in_idx: Index of the file descriptor in the array from which the program
 *         should read its input, or -1 if input should not be read from a pipe.
 * out_idx: Index of the file descriptor in the array to which the program
 *          should write its output, or -1 if output should not be written to
 *          a pipe.
 * Returns 0 on success or -1 on error.
 */
int run_piped_command(strvec_t *tokens, int *pipes, int n_pipes, int in_idx, int out_idx) {

    //close all unused pipes
    for (size_t i = 0; i < n_pipes*2; i++)
    {
        if(i != in_idx && i != out_idx){
            if(close(pipes[i]) == -1){
                return -1;
            }
        }
    }

    if(in_idx != -1){// set input if we need to
        if(dup2(pipes[in_idx], STDIN_FILENO) == -1){
            if(close(pipes[in_idx]) == -1){
                return -1;
            }
            if(close(pipes[out_idx]) == -1){
                return -1;
            }
            return -1;
        }
    }
    if(out_idx != -1){// set output if we need to 
        if(dup2(pipes[out_idx], STDOUT_FILENO) == -1){
            if(close(pipes[in_idx]) == -1){
                return -1;
            }
            if(close(pipes[out_idx]) == -1){
                return -1;
            }
            return -1;
        }
    }

    // run command
    if(run_command(tokens) == -1){
        if(close(pipes[in_idx]) == -1){
                return -1;
            }
        if(close(pipes[out_idx]) == -1){
                return -1;
            }
        return -1;
    }

    // close last two pipes before closing
    if(in_idx != -1){
        if(close(pipes[in_idx]) == -1){
            return -1;
        }
    }
    if(out_idx != -1){
        if(close(pipes[out_idx]) == -1){
            return -1;
        }
    }
    return 0;
}

int run_pipelined_commands(strvec_t *tokens) {
    // find number of pipes
    int n_pipes = strvec_num_occurrences(tokens, "|");

    //create the token for a single command
    strvec_t *cmd = malloc(sizeof(strvec_t));
    if(cmd == NULL){
        perror("malloc");
        return -1;
    }

    // create pipes
    int *fd = malloc(sizeof(int) * n_pipes * 2);
    if(fd == NULL){
        perror("malloc");
        return -1;
    }
    // open pipes
    for (size_t i = 0; i < n_pipes; i++)
    {
        if(pipe(fd+(i*2))){
            perror("opening pipes");
            free(cmd);
            free(fd);
            return -1;
        }
    } 

    // set up bounds for single command
    int start = tokens->length;
    int end = tokens->length;

    //loop to execute each command 
    for (int i = n_pipes; i >= 0; i--)
    {
        if(i != n_pipes){
        end = start;    // set end of tokens based on last start
        }
        start = strvec_find_last(tokens, "|"); // find the last | and then go one past to the command
        // no error checking needed as we take advantage of returning -1
        start++;// if no val 0 else we go one past the |

        // calculate the input and output pipes
        int input = -1;
        int output = -1;
        if(i != 0){
            input = (i-1)*2; 
        }
        if(i != n_pipes){
            output = (i*2)+1;
        }

        // take the last command only
        if(strvec_slice(tokens, cmd, start, end) == -1) {
            perror("strvec_slice");
            strvec_clear(cmd);
            free(cmd);
            return -1;
        }
        // remove the last command
        strvec_take(tokens, start-1);
            
        // branch off into a child and call run_piped_command
        pid_t child_pid = fork();
        if (child_pid == 0)
        {   
            // run the last command
            int ret_val = run_piped_command(cmd, fd, n_pipes, input, output);

            //free mem
            strvec_clear(cmd);
            free(cmd);
            // we exit using ret_val main will error check using it
            exit(ret_val);
        }
        // be sure to clear cmd when in main to be ready for next time
        strvec_clear(cmd);
    }

    //close all remaining pipes
    for (size_t i = 0; i < n_pipes*2; i++)
    {
        if(close(fd[i]) == -1){
                return -1;
        }
    }
    
    
    // wait for all children to complete
    for (int i = n_pipes; i >= 0; i--) {
        int status;
        wait(&status);
        // check that the children exited
        if (WEXITSTATUS(status) != 0) {
            perror("wait");
            free(fd);
            free(cmd);
            return -1;
        }
    }

    // final free
    free(fd);
    free(cmd);
    
    //return
    return 0;
}
