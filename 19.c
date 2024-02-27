#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Signal handler function for SIGTSTP (Ctrl-Z)
void stop_handler(int sig) {
    printf("Process stopped. Press Enter to resume...\n");
    fflush(stdout);
}

int main() {
    printf("Process running...\n");

    // Register signal handler for SIGTSTP (Ctrl-Z)
    signal(SIGTSTP, stop_handler);

    // Infinite loop to simulate the process running
    while (1) {
        // Sleeping state
        printf("Process sleeping...\n");
        sleep(5); // Sleep for 5 seconds
        
        // Back to running state
        printf("Process resumed...\n");
    }

    return 0;
}
