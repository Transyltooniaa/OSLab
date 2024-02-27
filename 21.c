#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    // Open a file for writing
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Fork a child process
    pid_t pid = fork();
    if (pid == -1) {
        // Error occurred
        perror("fork");
        close(fd);
        return 1;
    } else if (pid == 0) {
        // Child process
        dprintf(fd, "Child process writing to the file\n");
        close(fd);
        exit(0);
    } else {
        // Parent process
        dprintf(fd, "Parent process writing to the file\n");
        close(fd);
        // Wait for the child process to finish
        wait(NULL);
    }

    return 0;
}
