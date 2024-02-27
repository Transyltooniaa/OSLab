/*
Executing an Executable Program:
a. Execute a program using the exec system call. 
b. Pass input to an executable program (e.g., execute an executable as $./a.out name).
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <name>\n", argv[0]);
        return 1;
    }

    printf("Hello, %s!\n", argv[1]);
    return 0;
}
