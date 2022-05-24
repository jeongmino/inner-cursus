#include <stdio.h>
#include <errno.h>

int	main(void)
{
	printf("current errno: %d\n", errno);
	printf("currnet sys_nerr: %d\n", sys_nerr);
	perror("intented error\n");
	return (0);
}
