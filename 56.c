#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>

// Function to read the CPU's time stamp counter (TSC)
static inline uint64_t rdtsc() {
    unsigned int hi, lo;
    __asm__ __volatile__("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)lo) | (((uint64_t)hi) << 32);
}

int main() {
    uint64_t start, end;
    int i;

    start = rdtsc(); // Get start time

    for (i = 0; i < 100; ++i) {
        getppid(); // Execute getppid() system call
    }

    end = rdtsc(); // Get end time

    // Calculate elapsed time in CPU cycles
    uint64_t elapsed_cycles = end - start;

    // Print the elapsed time
    printf("Time taken for 100 getppid() calls: %lu CPU cycles\n", elapsed_cycles);

    return 0;
}
