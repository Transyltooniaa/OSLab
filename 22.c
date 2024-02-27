#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid > 0) {
        // Parent process
        printf("Parent process (PID = %d) created a child process (PID = %d)\n", getpid(), child_pid);
        sleep(10); // Parent process sleeps for 10 seconds without waiting for the child to terminate
    } else if (child_pid == 0) {
        // Child process
        printf("Child process (PID = %d) exiting...\n", getpid());
        exit(0); // Child process exits immediately
    } else {
        // Fork error
        perror("fork");
        return 1;
    }

    return 0;
}
