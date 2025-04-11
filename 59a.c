#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigsegv_handler(int signum) {
    printf("Caught SIGSEGV signal\n");
    exit(signum);
}

int main() {
    signal(SIGSEGV, sigsegv_handler);

    // Cause segmentation fault
    int *ptr = NULL;
    *ptr = 10;

    return 0;
}
