#include<stdio.h>
#include <stdarg.h>
#include <unistd.h>
int	ft_strlen(char *str)
{
	int cnt = 0;

	while (*str++)
		cnt++;
	return (cnt);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}	

int main(void)
{
	/*
    unsigned int num;
    int cnt = 0;
   	va_list ap;
	char *ptr;

	num = 4294967295;
	cnt = printf("%X\n", num);
	printf("%d", cnt); */

	char c = '\n';
	char *app = "apple";
	int cnt_c = ft_strlen(&c);
	int cnt_str = ft_strlen(app);

	printf("c : %d\n", cnt_c);
	printf("str : %d\n", cnt_str);
    return (0);
}
