#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/types.h>

struct birthday {
  int day;
  int month;
  int year;
  struct list_head list;
};

// The list head structure is defined in the include file <linux/types.h>
// Other Macros most defined in <linux/list.h>
static LIST_HEAD(birthday_list);

/* This function is called when the module is loaded. */
int simple_init(void) {

  printk(KERN_INFO "Loading Module\n");

  struct birthday *person;
  // like malloc function
  person = kmalloc(sizeof(*person), GFP_KERNEL);

  person->day = 2;
  person->month = 8;
  person->year = 1995;

  INIT_LIST_HEAD(&person->list);

  list_add_tail(&person->list, &birthday_list);

  struct birthday *ptr;

  list_for_each_entry(ptr, &birthday_list, list) {
    /*on each iteration ptr points*/
    /*to the next birthday struct*/
    printk(KERN_INFO "day:%d, month:%d, year: %d\n",
           ptr->day,
           ptr->month,
           ptr->year);
  }
  return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
  printk(KERN_INFO "Removing Module\n");
  struct birthday *ptr, *next;

  list_for_each_entry_safe(ptr, next, &birthday_list, list)
  {
    /*on each iteration ptr points*/
    /*to the next birthday struct*/
    printk(KERN_INFO "day:%d, month:%d, year:%d\n",
           ptr->day,
           ptr->month,
           ptr->year);
    list_del(&ptr->list);
    // like free function
    kfree(ptr);
  }
}

/* Macros for registering module entry and exit points. */
module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
