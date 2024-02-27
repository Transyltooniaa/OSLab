/*
Getting Maximum and Minimum Real-Time Priority: Develop a program to retrieve the 
maximum and minimum real-time priority.
*/

#include <stdio.h>
#include <sched.h>

int main() {
    int max_priority, min_priority;

    // Get the maximum real-time priority
    max_priority = sched_get_priority_max(SCHED_FIFO);
    if (max_priority == -1) {
        perror("Error getting maximum real-time priority");
        return 1;
    }

    // Get the minimum real-time priority
    min_priority = sched_get_priority_min(SCHED_FIFO);
    if (min_priority == -1) {
        perror("Error getting minimum real-time priority");
        return 1;
    }

    printf("Maximum real-time priority: %d\n", max_priority);
    printf("Minimum real-time priority: %d\n", min_priority);

    return 0;
}
