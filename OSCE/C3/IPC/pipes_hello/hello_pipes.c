// Note that ordinary pipes require a parent–child relationship between the communicating processes on both UNIX and Windows systems. This means that these pipes can be used only for communication between processes on the same machine.

#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(int argc, char const *argv[]) {
    char msg[BUFFER_SIZE] = "helloworld!";
    char msg_read[BUFFER_SIZE];

    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe failed");
        return 1;
    }

    pid = fork();
    printf("pid is : %d\n", pid);
    // parent process
    if (pid > 0) {
        close(fd[READ_END]);
        write(fd[WRITE_END], msg, strlen(msg) + 1);
        close(fd[WRITE_END]);
    } else if(pid == 0) {  // child process
        printf("%d\n", pid);
        close(fd[WRITE_END]);
        read(fd[READ_END], msg_read, BUFFER_SIZE);
        printf("%s\n", msg_read);
        close(fd[WRITE_END]);
    }

    return 0;
}
