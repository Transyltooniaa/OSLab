#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main() {
    char file_Name[100];
    printf("Enter the filename: ");
    scanf("%99s", file_Name); // Limiting input to avoid buffer overflow

    int fd = open(file_Name, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    printf("Lock setting...\n");

    struct flock lk;
    lk.l_type = F_RDLCK;
    lk.l_pid = getpid();
    lk.l_start = 0;
    lk.l_whence = SEEK_SET;
    lk.l_len = 0;

    // Set read lock
    int x = fcntl(fd, F_SETLKW, &lk);
    if (x == -1) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }

    getchar(); // Consume newline after Enter

    printf("Lock acquired.\nPress Enter to unlock...\n");

    getchar(); // Consume newline after Enter

    // Unlock
    lk.l_type = F_UNLCK;
    int y = fcntl(fd, F_SETLKW, &lk);
    
    if (y == -1) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
    printf("Unlocked.\n");

    close(fd);
    return 0;
}
