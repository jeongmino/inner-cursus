#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	di = 255;
	int	u = -255;
	unsigned int hex = 255;
	char	c = 'c';
	char	*str = "42seoul";
	int	ft_num = 0;
	int	num = 0;

	num = printf("printf di = %d, %i\n", di, di);
	ft_num = ft_printf("ft_printf di = %d, %i\n", di, di);
	printf("num = %d, ft_num = %d\n", num, ft_num);

    /*

	num = printf("printf u =  %u\n",di);
	ft_num = ft_printf("ft_printf u = %u\n", di);
	printf("num = %d, ft_num = %d\n", num, ft_num);

	num = printf("printf xX = %x, %X\n", hex, hex);
	ft_num = ft_printf("ft_printf xX = %x, %X\n", hex, hex);
	printf("num = %d, ft_num = %d\n", num, ft_num);

	num = printf("printf c = %c\n",c);
	ft_num = ft_printf("ft_printf c = %c\n",c);
	printf("num = %d, ft_num = %d\n", num, ft_num);
    */
	return (0);
}
