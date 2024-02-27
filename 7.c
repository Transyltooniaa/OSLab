#include <unistd.h>
#include <stdio.h>
#include <string.h> 
#include <sys/types.h>
#include <sys/stat.h> 
#include <fcntl.h>

#define BUFFER_SIZE 1024 

int main(void)
{
    char filename1[100], filename2[100], buf[BUFFER_SIZE];
    
    printf("Enter the source file name: ");
    scanf("%s", filename1);

    int fd1 = open(filename1, O_RDONLY);
    if (fd1 == -1) {
        perror("Error opening source file");
        return 1;
    }

    printf("Enter the destination file name: ");
    scanf("%s", filename2);

    int fd2 = open(filename2, O_WRONLY | O_CREAT);
    if (fd2 == -1) {
        perror("Error opening destination file");
        close(fd1);
        return 1;
    }

    ssize_t bytes_read, bytes_written;
    while ((bytes_read = read(fd1, buf, sizeof(buf))) > 0) {
        bytes_written = write(fd2, buf, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Write error");
            close(fd1);
            close(fd2);
            return 1;
        }
    }

    if (bytes_read == -1) {
        perror("Read error");
        close(fd1);
        close(fd2);
        return 1;
    }

    printf("File copied successfully.\n");

    close(fd1);
    close(fd2);

    return 0;
}
