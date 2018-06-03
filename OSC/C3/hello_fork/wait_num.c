// Just demo code show how to use fork system call create a process
// and get the child return value
// run as script: tcc -run wait_num.c

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(void) {

    pid_t pid;
    int status = 0;
    // fork a child process
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "fork error \n");
        return 1;
    } else if (pid == 0) {
        // in child process, fork() return 0 in child process
        // return child process id in parent process
        exit(10);
    } else {
        wait(&status);
        // use WEXITSTATUS(status) to get child exit value
        fprintf(stderr, "Child complete with num %d, parent exit.\n",
                WEXITSTATUS(status));
        exit(0);
    }

    return 0;
}
