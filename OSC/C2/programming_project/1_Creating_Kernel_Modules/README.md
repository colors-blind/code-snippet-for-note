- Use `lsmod` to list all kernel modules that are currently loaded like

```
[vagrant@chenwen code-snippets-for-note]$ lsmod
Module                  Size  Used by
nfs                   431415  1 
lockd                  74688  1 nfs
fscache                60813  1 nfs
auth_rpcgss            46084  1 nfs
nfs_acl                 2647  1 nfs
sunrpc                267379  15 nfs,lockd,auth_rpcgss,nfs_acl
dell_rbu                9414  0 
dcdbas                  8707  0 
vboxsf                 37955  1 
ip6t_REJECT             4372  2 
```

Edit ` simple.c ` like below code:

```
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


```

To complie to code with the `MakeFile`:

```
obj-m += simple.o
all:
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
```

make the code:

```
[vagrant@chenwen hello_k]$ make
make -C /lib/modules/2.6.32-696.3.1.el6.x86_64/build M=/home/admin/demo/hello_k modules
make[1]: Entering directory `/usr/src/kernels/2.6.32-696.3.1.el6.x86_64'
  Building modules, stage 2.
  MODPOST 1 modules
make[1]: Leaving directory `/usr/src/kernels/2.6.32-696.3.1.el6.x86_64'
```

install the module with:

```
sudo insmod simple.ko
```

use `dmesg` show the module is loading:

```
[vagrant@chenwen hello_k]$ dmesg
Hello is loading
11400862456688148481
jiffies is 4324584507 HZ is 1000 
```

delete the module with `sudo rmmod simple`


PS: for some header file in my VBox CentOS in `/usr/src/kernels/2.6.32-696.3.1.el6.x86_64/include/linux/`


