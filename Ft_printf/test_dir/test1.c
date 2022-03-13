#include <stdio.h>

int main(void)
{
    unsigned long long p;
    int *ptr;
    int num;
    
    num = 0;
    ptr = &num;
    p = (unsigned long long)ptr;

    printf("the result is : %llx\n", p);
    return (0);
}