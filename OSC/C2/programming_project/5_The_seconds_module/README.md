- seconds

```
Design a kernel module that creates a proc file named /proc/seconds
that reports the number of elapsed seconds since the kernel module was
loaded. This will involve using the value of jiffies as well as the HZ
rate. When a user enters the command

cat /proc/seconds

your kernel module will report the number of seconds that have
elapsed since the kernel module was first loaded. Be sure to remove
/proc/seconds when the module is removed.
```