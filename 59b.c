#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigint_handler(int signum) {
    printf("Caught SIGINT signal\n");
    exit(signum);
}

int main() {
    signal(SIGINT, sigint_handler);

    printf("Waiting for SIGINT signal...\n");
    while (1) {
        // Do nothing
    }

    return 0;
}
