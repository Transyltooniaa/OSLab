#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/stat.h>

int main() {
    int fd;
    char *fifo = "/tmp/myfifo";

    // Create the FIFO (named pipe)
    mkfifo(fifo, 0666);

    // Open the FIFO for reading
    fd = open(fifo, O_RDONLY | O_NONBLOCK); // Open in non-blocking mode

    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    fd_set read_fds;
    struct timeval timeout;

    // Set the timeout to 10 seconds
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    // Initialize the file descriptor set
    FD_ZERO(&read_fds);
    FD_SET(fd, &read_fds);

    // Wait for data to be available in the FIFO or timeout after 10 seconds
    int result = select(fd + 1, &read_fds, NULL, NULL, &timeout);

    if (result == -1) {
        perror("select");
        exit(EXIT_FAILURE);
    } else if (result == 0) {
        printf("No data available in FIFO after 10 seconds.\n");
    } else {
        printf("Data available in FIFO.\n");

        // Read data from the FIFO
        char buf[256];
        ssize_t bytes_read = read(fd, buf, sizeof(buf));

        if (bytes_read == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("Received data from FIFO: %s\n", buf);
    }

    // Close the FIFO
    close(fd);

    return 0;
}
