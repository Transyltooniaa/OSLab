#include<stdio.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include <sys/types.h>
#include<stdlib.h>

int main(){
    int msgid;

    key_t key;
    key=ftok(".",'a');
    msgid=msgget(key,IPC_CREAT|0644);
    printf("key value is %d\n",key);
    printf("key value in hex is 0x%x\n",key);
    printf("msgid value is %d\n",msgid);

}

