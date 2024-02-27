// Program : 5
// Name : Ajitesh Kumar Singh
// Roll No. : IMT2022559
// description: program that generates five new files in an infinite loop.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> // Include for close() function

#define FILE_COUNT 5 // Number of files to create

int main() {
    int i = 0;
    while (1) {
        if (i >= FILE_COUNT)
            break; // Exit loop after creating the desired number of files
        
        char filename[20];
        sprintf(filename, "file%d.txt", i);
        int fd = open(filename, O_CREAT | O_WRONLY, 0777);
        
        if (fd == -1) {
            perror("Error creating file");
            return 1;
        }
        close(fd); // Close the file descriptor after creating the file
        i++;
    }
    return 0;
}
