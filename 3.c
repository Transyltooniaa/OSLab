// Program : 3
// Name : Ajitesh Kumar Singh
// Roll No. : IMT2022559
// description: To create a program that creates a file and prints its file descriptor value using the creat() system call.

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    char fileName[100];
    printf("Enter the file name: ");
    scanf("%s", fileName);
    int fd = creat(fileName, 0744);
    printf("File descriptor value: %d\n", fd);
}
