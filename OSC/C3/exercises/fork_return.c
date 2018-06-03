// run as script: tcc -run fork_return.c

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

int main(void) {
    pid_t pid;
    pid_t pid1;
    pid = fork();
    // fork return child pid in parent porcess; return 0 in child process
    if (pid == 0) {
        pid1 = getpid();
        // 0 x
        printf("child pid : %d %d\n", pid, pid1);
    } else {
        pid1 = getpid();
        // x x-1
        printf("parent pid : %d %d\n", pid, pid1);
    }
    return 0;
}