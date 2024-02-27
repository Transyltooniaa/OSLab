/*
 Executing ls -Rl Using Various exec System Calls: Write a program to execute ls -Rl using 
the following system calls: 
a. execl 
b. execlp 
c. execle 
d. execv 
e. execvp
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Using execl:\n");
    execl("/bin/ls", "ls", "-Rl", NULL);

    printf("Using execlp:\n");
    execlp("ls", "ls", "-Rl", NULL);

    printf("Using execle:\n");
    char *envp[] = {NULL}; // Empty environment
    execle("/bin/ls", "ls", "-Rl", NULL, envp);

    printf("Using execv:\n");
    char *args[] = {"/bin/ls", "-Rl", NULL};
    execv("/bin/ls", args);

    printf("Using execvp:\n");
    execvp("ls", args);

    // If any of the exec calls fail
    perror("exec");
    return 1;
}
