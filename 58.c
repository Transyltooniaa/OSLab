#include <stdio.h>
#include <pthread.h>

// Function to be executed by each thread
void *thread_function(void *arg) {
    printf("Thread ID: %ld\n", pthread_self());
    return NULL;
}

int main() {
    pthread_t threads[3];
    int i;

    // Create three threads
    for (i = 0; i < 3; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return 1;
        }
    }

    // Wait for all threads to finish
    for (i = 0; i < 3; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread %d\n", i);
            return 1;
        }
    }

    return 0;
}
