#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int fd[2];
    pipe(fd);  //creating a pipe
    int x=fork();           //fork
    if(x==0){
        close(1);       //closing stdout
        close(fd[0]);
        dup(fd[1]);   //duping fd[1] into 1
        execlp("ls","ls","-l",NULL);        //executing ls -l
    }
    else{
        close(0);       //closing stdin
        close(fd[1]);       //closing fd[1] 
        dup(fd[0]);
        execlp("wc","wc",NULL);
    }

}