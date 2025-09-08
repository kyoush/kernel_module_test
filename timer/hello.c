#include <linux/module.h>
#include <linux/timer.h>

struct timer_list mytimer;

#define MYTIMER_TIMEOUT_SECS	10

static int mytimer_fn(struct timer_list *timer)
{
	pr_info("%d secs passed.\n" MYTIMER_TIMEOUT_SECS);
	return 0;
}

static int mymodule_init(void)
{
	pr_info("Hello world!\n");
	timer_setup(&mytimer, mytimer_fn, 0);
	mytimer.expires = jiffies + MYTIMER_TIMEOUT_SECS * HZ;
	add_timer(&mytimer);

	return 0;
}

static void __exit mymodule_exit(void)
{
	del_timer(&mytimer);
}

module_init(mymodule_init);
module_exit(mymodule_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Kyoshiro Kamura <kyoshi@kamura.email>");
MODULE_DESCRIPTION("A simple Hello World Linux kernel module");
