#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include<unistd.h>

// Semaphores
sem_t semaphore_A;
sem_t semaphore_B;

// Function for thread 1
void *thread_function_1(void *arg) {
    sem_wait(&semaphore_A); // Acquire semaphore A
    printf("Thread 1 acquired semaphore A\n");
    sleep(1); // Introduce delay to simulate work

    sem_wait(&semaphore_B); // Attempt to acquire semaphore B
    printf("Thread 1 acquired semaphore B\n");

    // Critical section
    // Do something with both resources

    sem_post(&semaphore_B); // Release semaphore B
    sem_post(&semaphore_A); // Release semaphore A

    pthread_exit(NULL);
}

// Function for thread 2
void *thread_function_2(void *arg) {
    sem_wait(&semaphore_B); // Acquire semaphore B
    printf("Thread 2 acquired semaphore B\n");
    sleep(1); // Introduce delay to simulate work

    sem_wait(&semaphore_A); // Attempt to acquire semaphore A
    printf("Thread 2 acquired semaphore A\n");

    // Critical section
    // Do something with both resources

    sem_post(&semaphore_A); // Release semaphore A
    sem_post(&semaphore_B); // Release semaphore B

    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    // Initialize semaphores
    sem_init(&semaphore_A, 0, 1);
    sem_init(&semaphore_B, 0, 1);

    // Create threads
    pthread_create(&thread1, NULL, thread_function_1, NULL);
    pthread_create(&thread2, NULL, thread_function_2, NULL);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy semaphores
    sem_destroy(&semaphore_A);
    sem_destroy(&semaphore_B);

    return 0;
}
