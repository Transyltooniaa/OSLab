#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
//run this code together with 37b

int main(){
    mkfifo("fifo_test2",0644);
    int fd=open("fifo_test2",O_WRONLY);
    write(fd,"hello",6*sizeof(char));
    close(fd);
    
}
