/*
Executing an Executable Program:
a. Execute a program using the exec system call. 
b. Pass input to an executable program (e.g., execute an executable as $./a.out name).
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Using execl to execute ls command
    execl("/bin/ls", "ls", "-l", NULL);
    
    // If execl fails
    perror("execl");
    return 1;
}
