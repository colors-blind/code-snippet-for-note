- Orphan process

This is [wiki](https://en.wikipedia.org/wiki/Orphan_process) definition:

> An orphan process is a computer process whose parent process has finished or terminated, though it remains running itself. Or orphan process is a process that is still executing, but whose parent has died. 


create orphan process with `orphan_process.c`:

```
// Just demo code show how to create a orphan process

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

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
        sleep(120);
        exit(0);
    } else {
        fprintf(stderr, "Child complete, parent exit.\n");
        exit(0);
    }

    return 0;
}
```

which ppid will become 1 and wait for init process to recovery:

```
F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
1 S   500 28108     1  0  80   0 -   980 hrtime pts/0    00:00:00 a.out
```

use `nohup` can make a process become orphan process intentionally like this way:

```
nohup python sleep.py > /dev/null  2>&1  &
```

when quit ssh session and re-login the system, the ppid will be 1:

```
F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S   500 28324     1  0  80   0 - 29570 poll_s ?        00:00:00 python
```
