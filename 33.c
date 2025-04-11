#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
    int fd1[2];
    int fd2[2];
    pipe(fd1);
    pipe(fd2);
    int x=fork();
    if(x==0){
        close(fd1[0]);          //closes read end of fd1
        close(fd2[1]);          //closes write end of fd2
        char buff[100];
        char string[21]="Hello parent process";
        write(fd1[1],string,21*sizeof(char));       //writes to fd1
        read(fd2[0],buff,100*sizeof(char));     //reads from fd2
        printf("Received from parent process: %s\n",buff);      //prints the content received from parent

    }
    else{
        close(fd1[1]);      //closes write end of fd1
        close(fd2[0]);   //closes read end of fd2
        char buffer[100];
        char string[20]="Hello child process";
        read(fd1[0],buffer,100*sizeof(char));       //reads from fd1
        write(fd2[1],string,20*sizeof(char));       //writes to fd2
        printf("Received from child process: %s\n",buffer);     //prints the content received from child
        
    }
}