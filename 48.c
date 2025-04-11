#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

int main() {
    sem_t binary_semaphore;
    sem_t counting_semaphore;

    // Initialize binary semaphore with initial value 1
    if (sem_init(&binary_semaphore, 0, 1) == -1) {
        perror("sem_init");
        exit(1);
    }

    // Initialize counting semaphore with initial value 5
    if (sem_init(&counting_semaphore, 0, 5) == -1) {
        perror("sem_init");
        exit(1);
    }

    printf("Semaphores initialized successfully.\n");

    // Destroy binary semaphore
    if (sem_destroy(&binary_semaphore) == -1) {
        perror("sem_destroy");
        exit(1);
    }

    // Destroy counting semaphore
    if (sem_destroy(&counting_semaphore) == -1) {
        perror("sem_destroy");
        exit(1);
    }

    printf("Semaphores destroyed successfully.\n");

    return 0;
}
