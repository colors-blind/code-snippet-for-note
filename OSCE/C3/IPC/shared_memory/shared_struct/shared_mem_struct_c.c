// run by : gcc shared_mem_struct_c.c -o c -lrt

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
    int shm_fd;
    container *memory;
    char *name = "test";

    shm_fd = shm_open(name, O_RDONLY, 0666);
    memory = (struct container*)mmap(0, sizeof(struct container), PROT_READ, MAP_SHARED, shm_fd, 0);

    printf("%d\n %d\n", memory->counter, memory->index);
    // remove shared memory object
    shm_unlink(name);

    return 0;
}