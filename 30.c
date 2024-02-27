#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

#define TASK_HOUR 22    // Hour of the day (24-hour format) to execute the task
#define TASK_MINUTE 52   // Minute of the hour to execute the task

// Function to perform the task
void performTask() {
    printf("Executing the task...\n");
    // Add your task execution code here
}

int main() {
    // Change the file mode mask
    umask(0);

    // Set up signal handlers

    if (!fork()) {
        setsid();
        chdir("/");
        umask(0);

        int taskExecuted = 0; // Flag to indicate if the task has been executed

        while (!taskExecuted) {
            time_t now = time(NULL);
            struct tm *tm_info = localtime(&now);

            if (tm_info == NULL) {
                perror("localtime");
                exit(EXIT_FAILURE);
            }

            // Clear the screen (optional)
            printf("\033[2J\033[H");

            printf("Time: %02d H : %02d M : %02d S\n", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);

            // Check if it's time to execute the task
            if (tm_info->tm_hour == TASK_HOUR && tm_info->tm_min == TASK_MINUTE) {
                printf("Daemon process is running...\n");
                performTask(); // Execute the task
                taskExecuted = 1; // Set the flag to exit the loop
            }

            // Sleep for one second
            sleep(1);
        }

        // Exiting the child process
        exit(0);
    } else {
        // Exiting the parent process
        exit(0);
    }

    return 0;
}
