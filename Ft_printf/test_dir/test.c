#include<stdio.h>
#include<stdarg.h>

int va_list_sum(int fixedArg1, int fixedArg2, ...)
{
    long long result;
	unsigned int tmp;
    va_list ap;

    result = 0;
    printf("first arg : %d\n", fixedArg1);
    printf("second arg : %d\n", fixedArg2);
    va_start(ap, fixedArg2);
    for(int i = 0; i < fixedArg1; i++)
    {
        tmp = va_arg(ap, unsigned int);
		printf("%p\n", &ap);
        printf("hex%d = %X\n", i + 1, tmp);
		result += tmp;
    }
    va_end(ap);
    return (result);
}

int main(void)
{
    unsigned int sum;
	unsigned int hex1, hex2;
	hex1 = 0xfe;
	hex2 = 0x1;
    sum = va_list_sum(2, 21, hex1, hex2);
    printf("5 + 3 = %X\n", sum);
}
