/*
Running a Script at a Specific Time with a Daemon Process: Create a program to execute a 
task at a specific time using a Daemon process.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

void task() {
    // Task to be executed at the specific time
    printf("Executing task at specific time...\n");
    // Add your task code here
}

int main() {
    // Daemonize the process
    if (daemon(0, 0) == -1) {
        perror("Error daemonizing process");
        exit(EXIT_FAILURE);
    }

    // Main loop
    while (1) {
        // Get current time
        time_t current_time;
        struct tm *timeinfo;
        time(&current_time);
        timeinfo = localtime(&current_time);

        // Check if it's the specific time (e.g., 12:00)
        if (timeinfo->tm_hour == 12 && timeinfo->tm_min == 0) {
            // Execute the task
            task();
            // Sleep to avoid repeated execution in the same minute
            sleep(60);
        } else {
            // Sleep until the next minute
            sleep(60 - timeinfo->tm_sec);
        }
    }

    return 0;
}
