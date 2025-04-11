#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
    char buffer[100];
    int fd=open("fifo_test2",O_RDONLY);
    read(fd,buffer,100*sizeof(char));
    printf("%s\n",buffer);
}