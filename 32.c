#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
     int fd[2];
    pipe(fd);       //creating a pipe
     char buffer[100];          //buffer to read data
    int x=fork();
    if(x!=0){                   //parent writing to fd[1]
        close(fd[0]);
        write(fd[1],"hello world",11*sizeof(char));        //writing to pipe
    }
    else{
        close(fd[1]);
        read(fd[0],buffer,100*sizeof(char));            //reading from pipe (fd[0])
        printf("%s\n",buffer);      //printing the content to ur terminal
    }
}