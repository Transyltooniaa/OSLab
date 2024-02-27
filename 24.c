/*
Creating and Waiting for Child Processes: Write a program to create three child processes. 
The parent process should wait for a specific child process using the waitpid system call.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid[3];
    int status;

    // Create three child processes
    for (int i = 0; i < 3; i++) {
        pid[i] = fork();

        if (pid[i] == -1) {
            // Error occurred
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid[i] == 0) {
            // Child process
            printf("Child process %d (PID = %d) created\n", i+1, getpid());
            sleep(i+1); // Child process sleeps for i+1 seconds
            printf("Child process %d (PID = %d) exiting\n", i+1, getpid());
            exit(EXIT_SUCCESS);
        }
    }

    // Parent process
    printf("Parent process (PID = %d) waiting for child process %d (PID = %d)\n", getpid(), 2, pid[1]);
    waitpid(pid[1], &status, 0);
    printf("Parent process (PID = %d) finished waiting\n", getpid());

    return 0;
}
