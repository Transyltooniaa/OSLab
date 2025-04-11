#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>

void sigalrm_handler(int signum) {
    printf("Caught SIGALRM signal\n");
    exit(signum);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = sigalrm_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGALRM, &sa, NULL);

    struct itimerval timer;
    timer.it_value.tv_sec = 2;   // 2 seconds
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    printf("Waiting for SIGALRM signal...\n");
    while (1) {
        // Do nothing
    }

    return 0;
}
