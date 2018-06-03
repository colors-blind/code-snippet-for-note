// complie by : gcc shared_mem_hello_s.c -o s -lrt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>


int main(int argc, char const *argv[]) {
    int size = 4096;
    char *name = "test";
    char *msg1 = "hello";
    char *msg2 = " world";

    int shm_fd;
    void *ptr;
    // create shared memory object
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

    // conf size of shared memory object
    ftruncate(shm_fd, size);

    // memory map the shared memory object
    ptr = mmap(0, size, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    // write to the shared memory object
    sprintf(ptr, "%s", msg1);
    ptr += strlen(msg1);
    sprintf(ptr, "%s", msg2);
    ptr += strlen(msg2);

    return 0;
}