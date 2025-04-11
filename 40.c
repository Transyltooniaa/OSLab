#define _GNU_SOURCE

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>



int main() {
    int p[2];
    pipe(p);

    int size=fcntl(p[0],F_GETPIPE_SZ);
    printf("size of pipe %d\n",size);

    printf("Max files opened within a process %ld\n",sysconf(_SC_OPEN_MAX));
}