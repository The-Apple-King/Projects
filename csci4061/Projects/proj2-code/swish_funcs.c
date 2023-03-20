#include "swish_funcs.h"

#include <assert.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "job_list.h"
#include "string_vector.h"

#define MAX_ARGS 10

int tokenize(char *s, strvec_t *tokens) {
  // TODO Task 0: Tokenize string s
  // Assume each token is separated by a single space (" ")
  // Use the strtok() function to accomplish this
  // Add each token to the 'tokens' parameter (a string vector)
  // Return 0 on success, -1 on error

  char *token = strtok(s, " ");  // first token
  while (token != NULL)          // while we have a token
  {
    if (strvec_add(tokens, token) ==
        -1) {  // add the token to the vector return -1 on error
      return -1;
    }
    token = strtok(NULL, " ");  // find next token
  }
  return 0;
}

int run_command(strvec_t *tokens) {
  // set group id so that signals affect this
  setpgid(STDIN_FILENO, getpid());
  // copied code from main to get signals to work here
  struct sigaction sac;
  sac.sa_handler = SIG_DFL;
  if (sigfillset(&sac.sa_mask) == -1) {
    perror("sigfillset");
    return 1;
  }
  sac.sa_flags = 0;
  if (sigaction(SIGTTIN, &sac, NULL) == -1 ||
      sigaction(SIGTTOU, &sac, NULL) == -1) {
    perror("sigaction");
    return 1;
  }

  char *args[MAX_ARGS];
  for (size_t i = 0; i < MAX_ARGS; i++)
  {
    args[i] = NULL;
  }
  

  for (size_t i = 0; i < tokens->length; i++) {
    
    // check if file input
    if (strcmp(tokens->data[i], "<") == 0) {
      i += 2;
      int input = open(tokens->data[i - 1], O_RDONLY);

      // check for errors in opening file
      if (input == -1) {
        perror("Failed to open input file");
      }

      // check for errors in updating input loc
      if (dup2(input, STDIN_FILENO) == -1) {
        perror("dup2 input");
        close(input);
      }
      
    }

    if (strcmp(tokens->data[i], ">") == 0) {  // if has > output
      i += 2;
      int output = open(tokens->data[i - 1], O_WRONLY);

      // check for errors in opening files
      if (output == -1) {
        perror("Failed to open output file");
      }

      // check for errors in updating output loc
      if (dup2(output, STDOUT_FILENO) == -1) {
        perror("dup2 output");
        close(output);
      }

    } else if (strcmp(tokens->data[i], ">>") == 0) {  // if has >> output
      i += 2;
      int output = open(tokens->data[i - 1], O_WRONLY | O_APPEND);

      // check for errors in opening files
      if (output == -1) {
        perror("Failed to open output file");
      }

      // check for errors in updating output loc
      if (dup2(output, STDOUT_FILENO) == -1) {
        perror("dup2 output append");
        close(output);
      }
    } else {  // if has just normal argument
      args[i] = tokens->data[i];
    }
  }

  if (execvp(args[0], args) == -1) {
    perror("exec");
  }

  // TODO Task 2: Execute the specified program (token 0) with the
  // specified command-line arguments
  // THIS FUNCTION SHOULD BE CALLED FROM A CHILD OF THE MAIN SHELL PROCESS
  // Hint: Build a string array from the 'tokens' vector and pass this into
  // execvp() Another Hint: You have a guarantee of the longest possible needed
  // array, so you won't have to use malloc.

  // TODO Task 3: Extend this function to perform output redirection before
  // exec()'ing Check for '<' (redirect input), '>' (redirect output), '>>'
  // (redirect and append output) entries inside of 'tokens' (the strvec_find()
  // function will do this for you) Open the necessary file for reading (<),
  // writing (>), or appending (>>) Use dup2() to redirect stdin (<), stdout (>
  // or >>) DO NOT pass redirection operators and file names to exec()'d program
  // E.g., "ls -l > out.txt" should be exec()'d with strings "ls", "-l", NULL

  // TODO Task 4: You need to do two items of setup before exec()'ing
  // 1. Restore the signal handlers for SIGTTOU and SIGTTIN to their defaults.
  // The code in main() within swish.c sets these handlers to the SIG_IGN value.
  // Adapt this code to use sigaction() to set the handlers to the SIG_DFL
  // value.
  // 2. Change the process group of this process (a child of the main shell).
  // Call getpid() to get its process ID then call setpgid() and use this
  // process ID as the value for the new process group ID

  // Not reachable after a successful exec(), but retain here to keep compiler
  // happy
  return 0;
}

int resume_job(strvec_t *tokens, job_list_t *jobs, int is_foreground) {
  int stat = 0;
  int tasknum = atoi(tokens->data[1]);
  job_t *job = job_list_get(jobs, tasknum);
  if (job == NULL) {
    fprintf(stderr, "Job index out of bounds\n");
    return -1;
  }
  if (is_foreground) {
    tcsetpgrp(STDIN_FILENO, job->pid);
    kill(job->pid, SIGCONT);
    waitpid(0, &stat, WUNTRACED);
    tcsetpgrp(STDIN_FILENO, getpid());
  } else {
    kill(job->pid, SIGCONT);
    job->status = JOB_BACKGROUND;
  }

  // TODO Task 5: Implement the ability to resume stopped jobs in the foreground
  // 1. Look up the relevant job information (in a job_t) from the jobs list
  //    using the index supplied by the user (in tokens index 1)
  //    Feel free to use sscanf() or atoi() to convert this string to an int
  // 2. Call tcsetpgrp(STDIN_FILENO, <job_pid>) where job_pid is the job's
  // process ID
  // 3. Send the process the SIGCONT signal with the kill() system call
  // 4. Use the same waitpid() logic as in main -- dont' forget WUNTRACED
  // 5. If the job has terminated (not stopped), remove it from the 'jobs' list
  // 6. Call tcsetpgrp(STDIN_FILENO, <shell_pid>). shell_pid is the *current*
  //    process's pid, since we call this function from the main shell process

  // TODO Task 6: Implement the ability to resume stopped jobs in the
  // background. This really just means omitting some of the steps used to
  // resume a job in the foreground:
  // 1. DO NOT call tcsetpgrp() to manipulate foreground/background terminal
  // process group
  // 2. DO NOT call waitpid() to wait on the job
  // 3. Make sure to modify the 'status' field of the relevant job list entry to
  // JOB_BACKGROUND
  //    (as it was JOB_STOPPED before this)

  return 0;
}

int await_background_job(strvec_t *tokens, job_list_t *jobs) {

  job_t* job = job_list_get(jobs, atoi(tokens->data[1]));
  if (job == NULL) {
    fprintf(stderr, "Job index out of bounds\n");
    return -1;
  }
  
  if(job->status == JOB_BACKGROUND){
    int stat = 0;
    waitpid(0, &stat, WUNTRACED);
    if (WIFSTOPPED(stat))// not stopped by signal
    {
      job_list_remove(jobs, atoi(tokens->data[1]));
    }
    
  }else{
    fprintf(stderr, "Job index is for stopped process not background process\n");
    return -1;
  }


  // TODO Task 6: Wait for a specific job to stop or terminate
  // 1. Look up the relevant job information (in a job_t) from the jobs list
  //    using the index supplied by the user (in tokens index 1)
  // 2. Make sure the job's status is JOB_BACKGROUND (no sense waiting for a
  // stopped job)
  // 3. Use waitpid() to wait for the job to terminate, as you have in
  // resume_job() and main().
  // 4. If the process terminates (is not stopped by a signal) remove it from
  // the jobs list

  return 0;
}

int await_all_background_jobs(job_list_t *jobs) {

  job_t *job = jobs->head;
  for (size_t i = 0; i < jobs->length; i++)
  {
    if(job->status == JOB_BACKGROUND){
      int stat = 0;
      waitpid(0, &stat, WUNTRACED);
      if(WIFSTOPPED(stat)){
        job->status = JOB_STOPPED;
      }
    }
  }
  job_list_remove_by_status(jobs, JOB_STOPPED);
  

  // TODO Task 6: Wait for all background jobs to stop or terminate
  // 1. Iterate through the jobs list, ignoring any stopped jobs
  // 2. For a background job, call waitpid() with WUNTRACED.
  // 3. If the job has stopped (check with WIFSTOPPED), change its
  //    status to JOB_STOPPED. If the job has terminated, do nothing until the
  //    next step (don't attempt to remove it while iterating through the list).
  // 4. Remove all background jobs (which have all just terminated) from jobs
  // list.
  //    Use the job_list_remove_by_status() function.

  return 0;
}
