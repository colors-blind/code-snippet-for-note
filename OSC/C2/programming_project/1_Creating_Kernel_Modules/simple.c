#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

#include <linux/hash.h>
#include <linux/gcd.h>

#include <linux/jiffies.h>

// when the module is loaded
int hello_init(voud) {
    printk(KERN_INFO "Hello is loading\n");
    printk(KERN_INFO "%lu\n", GOLDEN_RATIO_PRIME);
    printk(KERN_INFO "jiffies is %lu HZ is %lu \n", jiffies, HZ);
    return 0;
}

// when the module is removed
void hello_exit() {
    printk(KERN_INFO "Removing Module\n");
    printk(KERN_INFO "gcd of 3300 and 24 is %lu\n", gcd(3300, 24));
    printk(KERN_INFO "jiffies is %lu HZ is %lu \n", jiffies, HZ);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
