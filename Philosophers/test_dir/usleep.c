#include <stdio.h>

#include <unistd.h>

int	main(void)
{
	int	i = 0;

	while (1)
	{
		printf("%dsec\n", i++);
		usleep(1000 * 1000);
	}
	return (0);
}
