#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <fcntl.h>

union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
};

// Pass arg.val as command-line argument.
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./a.out <arg.val>\n");
        exit(1);
    }
    union semun arg;
    key_t key = ftok(".", 'a');
    int semid = semget(key, 1, IPC_CREAT | 0744);
    if (semid == -1)
    {
        printf("Unable to create semaphore.\n");
    }
    arg.val = atoi(argv[1]);
    int res = semctl(semid, 0, SETVAL, arg);
    if (res == 0)
    {
        printf("arg.val set to: %d\n", arg.val);
    }
    return (0);
}