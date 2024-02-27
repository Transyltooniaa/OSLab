#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid > 0) {
        // Parent process
        printf("Parent process (PID = %d) created a child process (PID = %d)\n", getpid(), child_pid);
        sleep(5); // Parent process sleeps for 5 seconds
        printf("Parent process (PID = %d) exiting...\n", getpid());
    } else if (child_pid == 0) {
        // Child process
        printf("Child process (PID = %d) sleeping...\n", getpid());
        printf("Child process (PID = %d) is now an orphan (parent PID = %d)\n", getpid(), getppid());
        sleep(10); // Child process sleeps for 10 seconds
        printf("Child process (PID = %d) exiting...\n", getpid());
    } else {
        // Fork error
        perror("fork");
        return 1;
    }

    return 0;
}
