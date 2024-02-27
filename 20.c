#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        // Fork failed
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process: PID = %d\n", getpid());
    } else {
        // Parent process
        printf("Parent process: PID = %d\n", getpid());
        printf("Parent created child process with PID = %d\n", pid);

        // Wait for the child process to finish
        wait(NULL);
        printf("Child process has terminated\n");
    }

    return 0;
}
