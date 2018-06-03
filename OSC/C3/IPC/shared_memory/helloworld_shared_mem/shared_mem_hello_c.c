// run by : gcc shared_mem_hello_s.c -o c -lrt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(int argc, char const *argv[]) {
    int size = 4096;
    char* name = "test";

    int shm_fd;
    void *ptr;

    shm_fd = shm_open(name, O_RDONLY, 0666);
    ptr = mmap(0, size, PROT_READ, MAP_SHARED, shm_fd, 0);

    printf("%s\n", (char*)ptr);
    // remove shared memory object
    shm_unlink(name);

    return 0;
}