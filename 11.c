#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

/*
File Descriptor Duplication and Appending: Write a program to open a file, duplicate the 
file descriptor, append the file with both descriptors, and verify whether the file is updated 
correctly. 
a. Use dup
b. Use dup2
c. Use fcntl
*/

int main() {
    char buffer_1[1000];
    char buffer_2[1000];
    char buffer_3[1000];
    char buffer_4[1000];

    int fd_1 = open("xyz3", O_WRONLY | O_APPEND);
    int fd_2 = dup(fd_1);

    write(fd_1, "Baa Baa Black Sheep\n", 20);
    write(fd_2, "Have you any wool?\n", 19);
    dup2(fd_1, 4);
    write(4, "Yes sir, yes sir\n", 16);

    int fd_3 = fcntl(fd_1, F_DUPFD, 0);
    
    write(fd_3, "Three bags full\n", 16);
    close(fd_1);
    close(fd_2);
    close(4);
    close(fd_3);
}