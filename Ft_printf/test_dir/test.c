#include<stdio.h>
#include<stdarg.h>

double va_list_sum(int fixedArg1, int fixedArg2, ...)
{
    double result;
    va_list ap;

    result = 0;
    printf("first arg : %d\n", fixedArg1);
    printf("second arg : %d\n", fixedArg2);
    va_start(ap, fixedArg2);
    for(int i = 0; i < fixedArg1; i++)
    {
        result += va_arg(ap, double);
    }
    va_end(ap);
    return (result);
}

int main(void)
{
    double sum;

    sum = va_list_sum(2, 21, 5.3, 3.1);
    printf("5.3 + 3.1 = %g\n", sum);
}
