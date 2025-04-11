#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sem.h>

struct ticket
{
    char *train_name;
    int ticket_num;
};

union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main()
{

    int fd = open("ticket_record.txt", O_RDWR | O_CREAT, 0744);
    struct ticket ticket1 = {"Rajdhani", 100};

    write(fd, &ticket1, sizeof(struct ticket));

    printf("Train name: %s\n", ticket1.train_name);
    printf("Ticket number: %d\n", ticket1.ticket_num);

    close(fd);

    int key = ftok(".", 'a');
    int sem_id = semget(key, 1, IPC_CREAT | 0666);

    union semun arg;
    arg.val = 1;
    semctl(sem_id, 0, SETVAL, arg);

    return 0;
}