#include <stdio.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>

/*
Waiting for STDIN Using Select: Develop a program to wait for input from STDIN for 10
seconds using select. Include proper print statements to verify data availability within the
specified time.
*/

int main() 
{
    // declare timeval structure
    struct timeval t;

    // set the time to 10 seconds
    t.tv_sec = 10;

    // set the microsecond to 0
    t.tv_usec = 0;

    // declare and initialize the file descriptor set
    fd_set read;

    // clear the file descriptor set
    FD_ZERO(&read);

    // add the file descriptor 0 to the file descriptor set
    FD_SET(0, &read);

    // wait for the data to be available
    int return_Value = select(1, &read, NULL, NULL, &t);

    // check the return value
    if (return_Value == 0)
    {
        printf("Data not available\n");
    }
    else if (return_Value > 0)
    {
        printf("Data is available.\n");
    }
}