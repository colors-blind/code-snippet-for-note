#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>

#define BUF_SIZE 128
#define PROC_NAME "seconds"

long unsigned start;

ssize_t proc_read(struct file* file, char __user* user_buf,
    size_t count, loff_t *pos);

static struct file_operations proc_ops = {
    .owner = THIS_MODULE,
    .read = proc_read,
};

int proc_init(void) {
    start = jiffies;
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
    static int current_sec = 0;
    if (comleted) {
        comleted = 0;
        return 0;
    }
    // here is a bug, if cat /proc/seconds twice in one second
    // the second one will not printed
    // but I don't know how to fix it...
    if (current_sec != (jiffies - start) / HZ) {
        rv = sprintf(buffer, "The seconds elapsed is : %lu\n", (jiffies - start) / HZ);
        current_sec = ((jiffies - start) / HZ);
    }

    /* copies kernel space buffer to user space usr_buf */
    copy_to_user(usr_buf, buffer, rv);

    return rv;
}

module_init(proc_init);
module_exit(proc_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("seconds Module");
MODULE_AUTHOR("SGG");

