#include<stdio.h>
#include<unistd.h>

void ft_putchar(char c)
{
    write(1, c, 1);
}

void ft_putstr(char *str)
{
    while (str)
        ft_putchar(*str++);
}

void printAdd(char  *str, void *addr)
{
    unsigned long long p;
    unsigned long long tmp;
    
    ft_putstr(str);
    p = (unsigned long long)addr;    
    tmp = p;
    while (tmp != 0)
    {
        
    }

}


int main(void)
{
    int sum;

    sum = 0;
    printf("The address of var sum is %p\n", &sum);
    printAdd("The Address of var sum is ", &sum);
    return (0);
}