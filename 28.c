#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    // Get the current priority of the process
    int old_priority = getpriority(PRIO_PROCESS, 0);
    printf("Old priority of the process: %d\n", old_priority);

    // Modify the priority using setpriority()
    if (setpriority(PRIO_PROCESS, 0, -10) == -1) {
        perror("setpriority");
        return 1;
    }

    // Get the new priority of the process
    int new_priority = getpriority(PRIO_PROCESS, 0);
    printf("New priority of the process: %d\n", new_priority);

    return 0;
}
