#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>

void sigvtalrm_handler(int signum) {
    printf("Caught SIGVTALRM signal\n");
    exit(signum);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = sigvtalrm_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGVTALRM, &sa, NULL);

    struct itimerval timer;
    timer.it_value.tv_sec = 2;   // 2 seconds
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    printf("Waiting for SIGVTALRM signal...\n");
    while (1) {
        // Do nothing
    }

    return 0;
}
