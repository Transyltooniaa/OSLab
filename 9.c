#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char *argv[]) {

    // define stat structure to store file attributes 
    struct stat fileStat;


    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &fileStat) < 0) {
        perror("Error");
        return 1;
    }

    // a. Inode
    printf("Inode: %ld\n", (long)fileStat.st_ino);

    // b. Number of hard links
    printf("Number of hard links: %ld\n", (long)fileStat.st_nlink);

    // c. UID
    printf("UID: %d\n", fileStat.st_uid);

    // d. GID
    printf("GID: %d\n", fileStat.st_gid);

    // e. Size
    printf("Size: %ld bytes\n", (long)fileStat.st_size);

    // f. Block size
    printf("Block size: %ld bytes\n", (long)fileStat.st_blksize);

    // g. Number of blocks
    printf("Number of blocks: %ld\n", (long)fileStat.st_blocks);

    // h. Time of last access
    printf("Time of last access: %s", ctime(&fileStat.st_atime));

    // i. Time of last modification
    printf("Time of last modification: %s", ctime(&fileStat.st_mtime));

    // j. Time of last change
    printf("Time of last change: %s", ctime(&fileStat.st_ctime));

    return 0;
}
