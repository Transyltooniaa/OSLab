#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>

#define FILENAME "18.txt"
#define RECORD_SIZE sizeof(int)

int main() {
    // Open the file for reading and writing
    int fd = open(FILENAME, O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Choose a record to access
    int record_number;
    printf("Choose a record (1, 2, or 3): ");
    scanf("%d", &record_number);
    if (record_number < 1 || record_number > 3) {
        printf("Invalid record number.\n");
        exit(EXIT_FAILURE);
    }

    // Prepare the lock
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (record_number - 1) * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;
    lock.l_pid = getpid();

    printf("Inside Critical Section\n");

    // Acquire the lock
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Read the current token number
    int tokennum;
    lseek(fd, (record_number - 1) * RECORD_SIZE, SEEK_SET);
    if (read(fd, &tokennum, RECORD_SIZE) == -1) {
        perror("read");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Increment the token number
    tokennum++;

    // Print the new token number
    printf("Token number is: %d\n", tokennum);

    // Write the updated token number back to the file
    lseek(fd, (record_number - 1) * RECORD_SIZE, SEEK_SET);
    if (write(fd, &tokennum, RECORD_SIZE) == -1) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Critical section Ends\n");

    // Sleep for demonstration purpose
    sleep(15);

    // Release the lock
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Unlock successful\n");

    // Close the file
    close(fd);

    return 0;
}
