// Just demo code show how to use fork system call create a process
// run as script: tcc -run hello_fork.c

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(void) {

    pid_t pid;
    // fork a child process
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "fork error \n");
        return 1;
    } else if (pid == 0) {
        // in child process, fork() return 0 in child process
        // return child process id in parent process
        execlp("/bin/ls", "ls", "-al", NULL);
    } else {
        wait(NULL);
        fprintf(stderr, "Child complete, parent exit.\n");
        exit(0);
    }

    return 0;
}
