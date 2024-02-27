// Program Number: 4
// Name: Ajitesh Kumar Singh
// Roll No: IMT2022559
// Description: To create a program to open an existing file in read-write mode.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd;
    char filename[100];
    printf("Enter the file name:");
    scanf("%s", filename);

    // O_EXCL is used to open the file in read-write mode only if the file already exists.
    int x = open(filename, O_EXCL | O_RDWR);

    printf("Return value: %d\n", x);

    return 0;

}

