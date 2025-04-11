#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main() {
    key_t key;
    int shmid;
    char *shmaddr;

    // Generate a key for the shared memory segment
    if ((key = ftok("0", '65')) == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Create a shared memory segment
    // 0666 is the permission mode
    // SHM_SIZE = shared memory segment size in bytes
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment
    
    // “Let the operating system choose the address where to attach this shared memory.”
    // This is the recommended and safest way to use shmat() unless you have a very specific reason to manually manage memory layout (which is rare and advanced).
    // 0 means read-write
    // void *custom_addr = (void *)0x5000000;
    if ((shmaddr = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Write some data to the shared memory
    // SHM_SIZE = shared memory segment size in bytes
    strncpy(shmaddr, "Hello, shared memory!", SHM_SIZE);

    // Attach with O_RDONLY and check if overwriting is possible
    char *readonly_addr = shmat(shmid, NULL, SHM_RDONLY);
    if (readonly_addr == (char *) -1) {
        perror("shmat O_RDONLY");
        exit(EXIT_FAILURE);
    }

    printf("Data in shared memory (O_RDONLY): %s\n", readonly_addr);

    // Detach the shared memory segment
    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    // Remove the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl IPC_RMID");
        exit(EXIT_FAILURE);
    }

    printf("Shared memory removed.\n");

    return 0;
}
