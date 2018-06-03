#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

// when the module is loaded
int hello_init(voud) {
    printk(KERN_INFO "Hello is loading\n");
    return 0;
}

// when the module is removed
void hello_exit() {
    printk(KERN_INFO "Removing Module\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
