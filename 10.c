// Program Number:10
// Name: Ajitesh Kumar Singh
// Roll No: IMT2022559
// Description: Open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes and write aga

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char filename1[1000], buf[1000];
    printf("Enter the filename:");
    scanf("%s", filename1);

    printf("Enter: ");
    scanf("%[^\n]", buf);
    int fd = open(filename1, O_RDWR);
    int x = write(fd, buf, 10);
    int y = lseek(fd, 10L, SEEK_CUR);

    printf("Enter: ");
    scanf("%[^\n]", buf);
    int z = write(fd, buf, 10);

    printf("First write: %d Iseek: %d Second write: %d\n", x, y, z);
    close(fd);
    // int b = system("od -c "+filename1);
}