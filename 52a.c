#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
// run this server, then run 51b.c
int main(){
    struct sockaddr_in server,client;
    char buf[1000];
    int sd = socket(AF_INET,SOCK_STREAM,0);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(5000);
    bind(sd,(struct sockaddr *)&server,sizeof(server));
    listen(sd,5);
    printf("Server listening on port 5000 : ");
    while(1){
        int len = sizeof(client);
        int nsd = accept(sd,(struct sockaddr *)&client,&len);
        int pid = fork();
        if(pid==0){ 
            printf("Handling client %s from child process with pid %d\n",inet_ntoa(client.sin_addr),getpid());
            read(nsd,buf,100);
            printf("Message from client: %s",buf);
            write(nsd,"Hello, from server\n",sizeof("Hello, from server\n"));
            close(nsd);
        }
        else close(nsd);
    }
}