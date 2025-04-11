#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(){
    int fd[2];
    pipe(fd);       //creating a pipe
    write(fd[1],"hello",5*sizeof(char));        //writing to pipe
    close(fd[1]);
    char buffer[100];
    read(fd[0],buffer,100*sizeof(char));            //reading from pipe
    printf("%s\n",buffer);      //printing the content to ur terminal
    close(fd[0]);
}
