#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>
#include <arpa/inet.h>

void *handleconnect(void *nsd) {
    int sd = *((int *)nsd);
    char buf[1000];
    read(sd, buf, 1000);
    printf("Message from client: %s", buf);
    write(sd, "Hello, from server\n", sizeof("Hello, from server\n"));
    close(sd);
    pthread_exit(NULL);
}

int main() {
    struct sockaddr_in serv, cli;
    pthread_t threads;
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    serv.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv.sin_family = AF_INET;
    serv.sin_port = htons(5000);
    bind(sd, (struct sockaddr *)&serv, sizeof(serv));
    listen(sd, 5);
    printf("Server listening on port 5000\n");
    while (1) {
        int len = sizeof(cli);
        int nsd = accept(sd, (struct sockaddr *)&cli, &len);
        pthread_create(&threads, NULL, handleconnect, (void *)&nsd);
    }
    close(sd);
    return 0;
}