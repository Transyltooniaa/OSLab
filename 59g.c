#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>

void sigprof_handler(int signum) {
    printf("Caught SIGPROF signal\n");
    exit(signum);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = sigprof_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGPROF, &sa, NULL);

    struct itimerval timer;
    timer.it_value.tv_sec = 2;   // 2 seconds
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);

    printf("Waiting for SIGPROF signal...\n");
    while (1) {
        // Do nothing
    }

    return 0;
}
