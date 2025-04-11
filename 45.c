#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(){
    key_t key;
    int msgid;
    struct msqid_ds buf;

     if ((key = ftok("/tmp", 'A')) == -1) {
        perror("error in ftok");
        exit(EXIT_FAILURE);
    }

    // Get the message queue ID
    if ((msgid = msgget(key, IPC_CREAT | 0644)) == -1) {
        perror("error in msgget");
        exit(EXIT_FAILURE);
    }

    // Get current attributes of the message queue
    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("error in msgctl");
        exit(EXIT_FAILURE);
    }

    // Change permissions to read and write for everyone
    buf.msg_perm.mode = 0633;

    // Update the attributes of the message queue
    if (msgctl(msgid, IPC_SET, &buf) == -1) {
        perror("Permissions could not be changed");
        exit(EXIT_FAILURE);
    }

    printf("Message queue permissions changed successfully.\n");

}