/*
 Getting and Modifying Scheduling Policy: Write a program to obtain the scheduling policy 
and modify it (e.g., SCHED_FIFO, SCHED_RR).
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main() {
    int policy;
    struct sched_param param;

    // Get the current scheduling policy
    policy = sched_getscheduler(0);
    if (policy == -1) {
        perror("Error getting scheduling policy");
        return 1;
    }

    printf("Current scheduling policy: ");
    switch (policy) {
        case SCHED_FIFO:
            printf("FIFO\n");
            break;
        case SCHED_RR:
            printf("Round Robin\n");
            break;
        case SCHED_OTHER:
            printf("Other (default)\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    // Modify the scheduling policy to SCHED_FIFO
    param.sched_priority = sched_get_priority_max(SCHED_FIFO);
    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1) {
        perror("Error setting scheduling policy");
        return 1;
    }

    printf("Scheduling policy modified to FIFO\n");

    return 0;
}
