// Program Number:1
// Name: Ajitesh Kumar Singh
// Roll No: IMT2022559
// Description: To create different types of files using shell commands


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 
#include<sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


int main(void)
{
    int choice;
    printf("1. soft link\n");
    printf("2. hard link\n");
    printf("3. fifo\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
    if (choice == 1)
    {
        char entered[1000], soft_file[1000];
        printf("Enter the file name:");
        scanf("%s", entered);
        printf("Enter the soft link file name:");
        scanf("%s", soft_file);
        int x = symlink(entered, soft_file);
        printf("Return value : %d\n", x);
    }

    else if (choice == 2)
    {

        char entered[1000], hard_file[1000];
        printf("Enter the file name:");
        scanf("%s", entered);
        printf("Enter the hard link file name:");
        scanf("%s", hard_file);
        int x = link(entered, hard_file);
        printf("Return value: %d\n", x);
    }

    else if (choice == 3)
    {
        char entered[1000], fifo_file[1000];
        printf("Enter the file name:");
        scanf("%s", entered);
        int x = mknod(entered, S_IFIFO, 0);
        printf("Return value: %d\n", x);
    }

    else
    {
        printf("Wrong choice");
    }

    return 0;
}