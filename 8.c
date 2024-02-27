#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

int main() {
    FILE *file;
    char filename[100];
    char line[MAX_LINE_LENGTH];

    // Get the file name from the user
    printf("Enter the file name: ");
    scanf("%s", filename);

    // Open the file in read-only mode
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read and display each line until the end of the file
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        printf("%s", line);
    }

    // Close the file
    fclose(file);

    return 0;
}
