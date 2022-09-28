/*
 *
 */
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int kprintf(char *kmsg)
{
	int dev_kmsg;
	int ret;

	if (!kmsg)
		return -EINVAL;
	dev_kmsg = open("/dev/kmsg", O_WRONLY);
	if (dev_kmsg < 0)
		return dev_kmsg;

	ret = write(dev_kmsg, kmsg, strlen(kmsg));
	if (ret != strlen(kmsg)) 
		return ret;
	
	close(dev_kmsg);


	return 0;
}

