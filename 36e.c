#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
int main() {
    printf("Enter file name");
    char filename[100];
    scanf("%s",filename);
    mkfifo(filename,0644);   //create a fifo file   in 0644 mode i.e. read and write permission for owner and read permission for others


}