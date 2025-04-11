#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX_MSG_SIZE 256

struct msg_buffer {
    long msg_type;
    char msg_text[MAX_MSG_SIZE];
};

int main(){
    int msgid;

    key_t key;
    key=ftok(".",'a');
    msgid=msgget(key,IPC_CREAT|0644);
    struct msg_buffer buf;

    msgrcv(msgid,&buf,MAX_MSG_SIZE,1,0);
    printf("%s\n",buf.msg_text);
    
    

}