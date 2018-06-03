// Just demo code show child process has its own copy
// run as script: tcc -run child_copy_var.c

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(void) {
    int v = 15;
    pid_t pid;
    // fork a child process
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "fork error \n");
        return 1;
    } else if (pid == 0) {
        v += 5;
        printf("child v is: %d\n", v);
    } else {
        wait(NULL);
        printf("parent v is: %d\n", v);
        fprintf(stderr, "Child complete, parent exit.\n");
        exit(0);
    }

    return 0;
}