#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	fd;

	fd = 4;
	int	arr[fd];

	printf("sizeof : %lu\n", sizeof(arr));
	return (0);
}
