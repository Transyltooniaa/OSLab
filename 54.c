#include <stdio.h>
#include <sys/resource.h>

void print_resource_limit(int resource) {
    struct rlimit rlim;
    
    // Get resource limit
    if (getrlimit(resource, &rlim) == 0) {
        printf("Resource: ");
        switch (resource) {
            case RLIMIT_CORE:
                printf("Core file size (bytes)\n");
                break;
            case RLIMIT_CPU:
                printf("CPU time (seconds)\n");
                break;
            case RLIMIT_DATA:
                printf("Data segment size (bytes)\n");
                break;
            case RLIMIT_FSIZE:
                printf("File size (bytes)\n");
                break;
            case RLIMIT_NOFILE:
                printf("Number of open files\n");
                break;
            case RLIMIT_STACK:
                printf("Stack size (bytes)\n");
                break;
            default:
                printf("Unknown resource\n");
                break;
        }

        // Print soft and hard limits
        printf("Soft limit: %lu\n", rlim.rlim_cur);
        printf("Hard limit: %lu\n", rlim.rlim_max);
    } else {
        printf("Failed to get resource limit\n");
    }
}

int main() {
    // Print resource limits for various resources
    print_resource_limit(RLIMIT_CORE);
    print_resource_limit(RLIMIT_CPU);
    print_resource_limit(RLIMIT_DATA);
    print_resource_limit(RLIMIT_FSIZE);
    print_resource_limit(RLIMIT_NOFILE);
    print_resource_limit(RLIMIT_STACK);

    return 0;
}

