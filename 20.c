#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();  // Create a child process

    if (pid == -1) {
        perror("fork");  // Fork failed
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0) {  
        // Child process
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        fflush(stdout);  // Ensure output is printed before exit
        exit(EXIT_SUCCESS);  // Exit successfully
    } 
    else {  
        // Parent process
        printf("Parent Process: PID = %d, Created Child PID = %d\n", getpid(), pid);
        fflush(stdout);

        int status;
        waitpid(pid, &status, 0);  // Wait for the child process

        if (WIFEXITED(status)) {
            printf("Child PID %d exited with status %d\n", pid, WEXITSTATUS(status));
        } else {
            printf("Child PID %d terminated abnormally\n", pid);
        }
    }

    return 0;
}
