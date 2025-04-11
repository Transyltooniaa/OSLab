#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

int main(){
    key_t key;
    int msgid;
    struct msqid_ds buf;

    // Generate a key for the message queue
    if ((key = ftok(".", 'a')) == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Get the message queue ID
    if ((msgid = msgget(key, IPC_CREAT | 0666)) == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // Get information about the message queue
    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    // Access permission
    printf("Access permission: %o\n", buf.msg_perm.mode);

    // UID and GID
    printf("UID of owner: %d\n", buf.msg_perm.uid);
    printf("GID of owner: %d\n", buf.msg_perm.gid);

    // Time of last message sent and received
    printf("Time of last message sent: %s", ctime(&buf.msg_stime));
    printf("Time of last message received: %s", ctime(&buf.msg_rtime));

    // Time of last change in the message queue
    printf("Time of last change in the message queue: %s", ctime(&buf.msg_ctime));

    // Size of the queue
    printf("Size of the queue: %ld bytes\n", buf.__msg_cbytes);

    // Number of messages in the queue
    printf("Number of messages in the queue: %ld\n", buf.msg_qnum);

    // Maximum number of bytes allowed
    printf("Maximum number of bytes allowed: %ld\n", buf.msg_qbytes);

    // PID of the msgsnd and msgrcv
    printf("PID of the msgsnd: %d\n", buf.msg_lspid);
    printf("PID of the msgrcv: %d\n", buf.msg_lrpid);

}