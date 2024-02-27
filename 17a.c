#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

/*
 Online Ticket Reservation Simulation: Develop a program to simulate online ticket 
reservation with the implementation of a write lock. Write one program to open a file, store 
a ticket number, and exit. Write a separate program to open the file, implement a write 
lock, read the ticket number, increment the number, print the new ticket number, and then 
close the file.

*/

int main() {
    int buffer = 0;
    int fd = open("ticket.txt", O_RDWR|O_CREAT);
    write(fd, &buffer, sizeof(int));
}