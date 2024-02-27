#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>

int main() {
    int fd = open("ticket.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Set write lock
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    printf("Inside critical section\n");

    // Acquire the lock
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Read the current ticket number
    int token_number = 0;
    if (read(fd, &token_number, sizeof(int)) == -1) {
        perror("read");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Increment the ticket number
    token_number++;

    // Print the new ticket number
    printf("Token number is: %d\n", token_number);

    // Write the updated ticket number back to the file
    lseek(fd, 0, SEEK_SET);
    if (write(fd, &token_number, sizeof(int)) == -1) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Critical section end\n");
    printf("Press Enter to unlock\n");
    getchar();

    // Release the lock
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Unlock successful\n");
    close(fd);

    return 0;
}
