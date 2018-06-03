// run as script: tcc -run num_of_processes.c

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

int main(void) {
    // every time fork(), every porcess create a new process
    // so there are 8 processes.
    fork();
    fork();
    fork();
    sleep(60);
    return 0;
}