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
    
    while((n = read(0, buffer, 100)) > 0)
    {   
        write(1, buffer, n);
    }
}