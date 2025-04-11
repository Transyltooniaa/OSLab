#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigfpe_handler(int signum) {
    printf("Caught SIGFPE signal\n");
    exit(signum);
}

int main() {
    signal(SIGFPE, sigfpe_handler);

    // Cause floating-point exception (division by zero)
    int a = 10, b = 0;
    int result = a / b;

    return 0;
}
