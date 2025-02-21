#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
// select() is a multiplexing function that monitors multiple file descriptors (FDs) simultaneously and waits for any of them to become ready for I/O (reading, writing, or error conditions).
int main() {
    fd_set read_fds;  // File descriptor set
    struct timeval timeout; // Timeout structure
    
    FD_ZERO(&read_fds);               // Clears (zeroes out) all file descriptors in read_fds. t  Ensures no garbage values from previous operations.
    FD_SET(STDIN_FILENO, &read_fds);  // Monitor STDIN (fd = 0)

    timeout.tv_sec = 10;  // 10-second timeout
    timeout.tv_usec = 0; // No microseconds (0) If not initialized, it may hold garbage values → unpredictable behavior.

    printf("Waiting for input (10 seconds)...\n");

    int ret = select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &timeout);
    // select( highest_fd + 1, read_fds, write_fds, error_fds, timeout)
    // NULL : These are for write FDs and exceptional conditions (like out-of-band data on a socket).
    // Since we're only reading from STDIN, we pass NULL.

    if (ret == -1) {
        perror("select() failed");
        exit(EXIT_FAILURE);
    } else if (ret == 0) {
        printf("Timeout! No input received within 10 seconds.\n");
    } else {
        char buffer[100];
        int bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
        if (bytes_read > 0) {
            buffer[bytes_read] = '\0';  // Null-terminate input
            printf("Received input: %s\n", buffer);
        } else {
            perror("read() failed");
        }
    }

    return 0;
}
