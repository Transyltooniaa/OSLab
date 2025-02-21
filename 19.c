#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Signal handler for SIGTSTP (Ctrl+Z)
void stop_handler(int sig) {
    printf("\nProcess stopped. Press Enter to resume...\n");
    fflush(stdout);
    
    // Wait for Enter key
    getchar();  
    printf("Resuming process...\n");
}

int main() {
    printf("Process running... Press Ctrl+Z to stop.\n");

    // Register signal handler for SIGTSTP (Ctrl+Z)
    signal(SIGTSTP, stop_handler);

    // Infinite loop to simulate process execution
    while (1) {
        printf("Process sleeping...\n");
        sleep(5);
        printf("Process resumed...\n");
    }

    return 0;
}
