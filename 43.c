#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX_MSG_SIZE 256

//run with q44a which will receive the msg

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
    buf.msg_type=1L;

    strcpy(buf.msg_text,"hello");
    printf("%s\n",buf.msg_text);

    msgsnd(msgid,&buf,strlen(buf.msg_text)+1,0);

}