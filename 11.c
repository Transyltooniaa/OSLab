#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "test.txt"
#define MESSAGE_1 "Written using original FD\n"
#define MESSAGE_2 "Written using dup FD\n"
#define MESSAGE_3 "Written using dup2 FD\n"
#define MESSAGE_4 "Written using fcntl FD\n"

int main() {
    // Open the file in append mode
    int fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    
    // Duplicate file descriptor using dup
    int fd_dup = dup(fd);
    if (fd_dup == -1) {
        perror("dup failed");
        close(fd);
        return 1;
    }
    
    // Duplicate file descriptor using dup2
    int fd_dup2 = dup2(fd, 10);  // Choosing 10 as an arbitrary descriptor
    if (fd_dup2 == -1) {
        perror("dup2 failed");
        close(fd);
        close(fd_dup);
        return 1;
    }
    
    // Duplicate file descriptor using fcntl
    int fd_fcntl = fcntl(fd, F_DUPFD, 20);  // Choosing 20 as an arbitrary descriptor
    if (fd_fcntl == -1) {
        perror("fcntl failed");
        close(fd);
        close(fd_dup);
        close(fd_dup2);
        return 1;
    }
    
    // Write to file using original and duplicated descriptors
    write(fd, MESSAGE_1, strlen(MESSAGE_1));
    write(fd_dup, MESSAGE_2, strlen(MESSAGE_2));
    write(fd_dup2, MESSAGE_3, strlen(MESSAGE_3));
    write(fd_fcntl, MESSAGE_4, strlen(MESSAGE_4));
    
    // Close all file descriptors
    close(fd);
    close(fd_dup);
    close(fd_dup2);
    close(fd_fcntl);
    
    printf("File written successfully. Check '%s' for content.\n", FILE_NAME);
    return 0;
}
