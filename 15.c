#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main() {
    int i = 0;

    // Check if environ is NULL to avoid potential segmentation fault
    if (environ == NULL) {
        fprintf(stderr, "Error: Environmental variables not available.\n");
        return EXIT_FAILURE;
    }

    printf("Environmental Variables:\n");

    // Iterate through the environmental variables and display them
    while (environ[i] != NULL) {
        printf("%s\n", environ[i]);
        i++;
    }

    return EXIT_SUCCESS;
}
