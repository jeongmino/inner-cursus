#include <stdlib.h>

int ft_ulti_range_index(int **range, int min, int max)
{
    int *arr;
    int i;
    int return_range;

    if (min >= max)
        return (0);
    return_range = max - min;
    arr = (int *)malloc(return_range * sizeof(int));
    if (arr == NULL)
    {
        *range = 0;
        return (-1);
    }
    *range = arr;
    i = 0;
    while (min < max)
    {
        arr[i] = min;
        min++;
        i++;
    }
    return (return_range);
}

int ft_ulti_range_ptr(int **range, int min, int max)
{
    int *arr;
    int return_range;

    if (min >= max)
        return (0);
    return_range = max - min;
    arr = (int *)malloc(return_range * sizeof(int));
    if (arr == NULL)
    {
        *range = NULL;
        return (-1);
    }
    *range = arr;
    while (min < max)
        *arr++ = min++;
    return (return_range);
}

#include <stdio.h>

void    print_arr(int *arr, int len)
{
    while (len-- > 0)
        printf("%d\t", *arr++);
    putchar('\n');
    return ;
}

int main(void)
{
    int *index_arr;
    int *ptr_arr;

    ft_ulti_range_index(&index_arr, 1, 5);
    ft_ulti_range_ptr(&ptr_arr, 1, 5);
    print_arr(index_arr, 4);
    print_arr(ptr_arr, 4);
    free(index_arr);
    free(ptr_arr);
    return (0);
}
