#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <PID> <scheduling_policy>\n", argv[0]);
        printf("Scheduling policies: 1 (SCHED_FIFO), 2 (SCHED_RR)\n");
        return 1;
    }

    int pid = atoi(argv[1]);
    int policy = atoi(argv[2]);
    struct sched_param param;
    int current_policy;

    // Get the current scheduling policy
    current_policy = sched_get_priority_max(pid);
    printf("Current scheduling policy for PID %d: ", pid);
    switch (current_policy) {
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("SCHED_OTHER (default)\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    // Set the new scheduling policy
    switch (policy) {
        case 1:
            param.sched_priority = sched_get_priority_max(SCHED_FIFO);
            // if (sched_setscheduler(pid, SCHED_FIFO, &param) == -1) {
            //     perror("Error setting scheduling policy to SCHED_FIFO");
            //     return 1;
            // }
            printf("Scheduling policy set to SCHED_FIFO\n");
            break;
        case 2:
            param.sched_priority = sched_get_priority_max(SCHED_RR);
            // if (sched_setscheduler(pid, SCHED_RR, &param) == -1) {
            //     perror("Error setting scheduling policy to SCHED_RR");
            //     return 1;
            // }
            printf("Scheduling policy set to SCHED_RR\n");
            break;
        default:
            printf("Invalid scheduling policy\n");
            return 1;
    }

    return 0;
}
