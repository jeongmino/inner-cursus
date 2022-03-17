#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>
int	main(void)
{
	int	di = 0;
	int	u = -100;
	unsigned int hex = 255;
	char	*str = "42seoul";
	int	ft_num = 200;
	int	num = 0;

    num = 100;
    
    num = printf("%p\n ", (void *)15);
    ft_num = ft_printf("%p\n ", (void *)15);
	printf("num = %d, ft_num = %d\n", num, ft_num);

	return (0);
}
