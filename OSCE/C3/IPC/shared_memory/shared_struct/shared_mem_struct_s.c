// complie by : gcc shared_mem_struct_s.c -o s -lrt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>


typedef struct container {
    int counter;
    int index;
}container;

int main(int argc, char const *argv[]) {
    int size = 4096;
    char *name = "test";
    container *memory;

    memory->index = 0;

    int shm_fd;
    // create shared memory object
    shm_fd = shm_open(name, O_CREAT | O_RDWR | O_EXCL, 0666);

    // conf size of shared memory object
    ftruncate(shm_fd, sizeof(struct container));

    // memory map the shared memory object
    memory = (struct container*)mmap(0, sizeof(struct container), PROT_WRITE, MAP_SHARED, shm_fd, 0);

    memory->counter = 100;

    return 0;
}