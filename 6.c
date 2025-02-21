// Program : 5
// Name : Ajitesh Kumar Singh
// Roll No. : IMT2022559
// description: a program to take input from STDIN and display it on STDOUT using only read/write system calls.


#include <stdio.h>
#include<string.h>
#include <fcntl.h>
#include <unistd.h> // Include for close() function


int main(void)
{
    char buffer[100];
    int n;
    
    // read() and write() system calls
    // read() reads from the file descriptor (FD) 0 (STDIN) . syntax: ssize_t read(int fd, void *buf, size_t count); where count is the number of bytes to read.
    // write() writes to the file descriptor (FD) 1 (STDOUT). syntax: ssize_t write(int fd, const void *buf, size_t count);
    while((n = read(0, buffer, 100)) > 0)
    {   
        write(1, buffer, n);
    }
}