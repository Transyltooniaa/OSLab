#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigsegv_handler(int signum) {
    printf("Caught SIGSEGV\n");
    exit(signum);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = sigsegv_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    // Cause a segmentation fault
    int *ptr = NULL;
    *ptr = 42;

    return 0;
}
