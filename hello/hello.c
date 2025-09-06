#include <linux/module.h>

static int __init hello_init(void)
{
	pr_info("Hello World!\n");
	return 0;
}

static void __exit hello_exit(void)
{
	pr_info("Goodbye world\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Kyoshiro Kamura <kyoshi@kamura.email>");
MODULE_DESCRIPTION("A simple Hello World Linux kernel module");

