- /proc file system

```
The /proc file system is a "pseudo" file system that exists only in kernel memory
and is used primarily for querying various kernel and per-process statistics.
```

- make a "hello world" about /proc/hello

hello.c

```
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>

#define BUF_SIZE 128
#define PROC_NAME "hello"

ssize_t proc_read(struct file* file, char __user* user_buf,
    size_t count, loff_t *pos);

static struct file_operations proc_ops = {
    .owner = THIS_MODULE,
    .read = proc_read,
};

int proc_init(void) {
    /* creates the /proc/hello entry */
    proc_create(PROC_NAME, 0666, NULL, &proc_ops);

    return 0;
}

void proc_exit(void) {
    /* removes the /proc/hello entry */
    remove_proc_entry(PROC_NAME, NULL);
}


ssize_t proc_read(struct file* file, char __user* usr_buf,
    size_t count, loff_t *pos) {
    int rv = 0;
    char buffer[BUF_SIZE];
    static int comleted = 0;

    if (comleted) {
        comleted = 0;
        return 0;
    }

    rv = sprintf(buffer, "Hello world!\n");

    /* copies kernel space buffer to user space usr_buf */
    copy_to_user(usr_buf, buffer, rv);

    return rv;
}

module_init(proc_init);
module_exit(proc_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Hello Module");
MODULE_AUTHOR("SGG");

```

make the code:

```
$ make             
make -C /lib/modules/2.6.32-696.3.1.el6.x86_64/build M=/home/admin/github/code-snippets-for-note/OSC/C2/programming_project/3_The_Proc_File_System modules
make[1]: Entering directory `/usr/src/kernels/2.6.32-696.3.1.el6.x86_64'
  Building modules, stage 2.
  MODPOST 1 modules
make[1]: Leaving directory `/usr/src/kernels/2.6.32-696.3.1.el6.x86_64'
```

install:

```
$ sudo insmod hello.ko 
```

try result:

```
$ cat /proc/hello

Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
Hello world!
^CHello world!
Hello world!
Hello world!
```

rm module:

```
sudo rmmod hello
```

try rm result:

```
$ cat /proc/hello
cat: /proc/hello: 没有那个文件或目录
```