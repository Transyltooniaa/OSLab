#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h> // for PATH_MAX
#include <string.h> // for strcat

void get_opening_mode(int fd) {
    int flags = fcntl(fd, F_GETFL);
    
    if (flags == -1) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }

    if (flags & O_RDWR)
        printf("Opening Mode: READ/WRITE\n");
    else if (flags & O_WRONLY)
        printf("Opening Mode: WRITE ONLY\n");
    else if (flags & O_RDONLY)
        printf("Opening Mode: READ ONLY\n");
    else
        printf("Opening Mode: UNKNOWN\n");
}

int main() {
    char file_name[256];
    char full_path[PATH_MAX];

    printf("Enter the name of the file: ");
    scanf("%255s", file_name);

    if (realpath(file_name, full_path) == NULL) {
        perror("realpath");
        exit(EXIT_FAILURE);
    }

    int fd = open(full_path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    get_opening_mode(fd);

    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    return 0;
}
