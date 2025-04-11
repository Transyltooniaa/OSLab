#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FIFO_PATH "/tmp/my_fifo"

int main() {
    // Create the FIFO (named pipe)
    mkfifo(FIFO_PATH, 0666);

    // Open the FIFO for reading and writing
    int fd = open(FIFO_PATH, O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Loop for communication
    while (1) {
        char buffer[256];

        // Read from the FIFO
        ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
        if (bytes_read == -1) {
            perror("read");
            exit(1);
        }

        // Null-terminate the string
        buffer[bytes_read] = '\0';

        // Display the message received from the client
        printf("Client: %s\n", buffer);

        // Check if the client wants to exit
        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        // Get input from the server
        printf("Server: ");
        fgets(buffer, sizeof(buffer), stdin);

        // Write to the FIFO
        if (write(fd, buffer, strlen(buffer)) == -1) {
            perror("write");
            exit(1);
        }
    }

    // Close the FIFO
    close(fd);

    // Remove the FIFO
    unlink(FIFO_PATH);

    return 0;
}
