#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

void identify_file_type(const char *filename) {
    struct stat st;

    // Check if file exists
    if (stat(filename, &st) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    // Identify file type based on st_mode
    if (S_ISREG(st.st_mode)) {
        printf("%s is a Regular file\n", filename);
    } else if (S_ISDIR(st.st_mode)) {
        printf("%s is a Directory\n", filename);
    } else if (S_ISCHR(st.st_mode)) {
        printf("%s is a Character device\n", filename);
    } else if (S_ISBLK(st.st_mode)) {
        printf("%s is a Block device\n", filename);
    } else if (S_ISFIFO(st.st_mode)) {
        printf("%s is a FIFO/pipe\n", filename);
    } else if (S_ISLNK(st.st_mode)) {
        printf("%s is a Symbolic link\n", filename);
    } else if (S_ISSOCK(st.st_mode)) {
        printf("%s is a Socket\n", filename);
    } else {
        printf("%s is of an Unknown type\n", filename);
    }
}

int main(int argc, char *argv[]) {
    // Check if filename is provided as command-line argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get filename from command-line argument
    char *filename = argv[1];

    // Identify the type of file
    identify_file_type(filename);

    return 0;
}
