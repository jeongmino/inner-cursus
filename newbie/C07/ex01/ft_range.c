#include <stdlib.h>

int	*ft_range_index(int min, int max)
{
	int	*arr;
    int i;

	if (min >= max)
		return (NULL);
    arr = (int *)malloc((max - min) * sizeof(int));
    if (arr == NULL)
        return (NULL);
    i = 0;
    while (min < max)
    {
        arr[i] = min;
        i++;
        min++;
    }
    return (arr);
}

int *ft_range_ptr(int min, int max) // ptr with 빡빡하게
{
    int *arr;
    int *tmp;

    if (min >= max)
        return (NULL);
    arr = (int *)malloc((max - min) * sizeof(int));
    if (!arr)
        return (arr);
    tmp = arr;
    while (min < max)
        *tmp++ = min++;
    return (arr);
}

#include <stdlib.h>
#include <stdio.h>

int	*ft_range_index(int min, int max);
int *ft_range_ptr(int min, int max);

void    put_int_arr(int *arr, int arr_size)
{
    int i;

    i = -1;
    while (++i < arr_size)
        printf("%d\t", arr[i]);
    putchar('\n');
    return ;
}

int main(void)
{
    int *index_arr;
    int *ptr_arr;

    index_arr = ft_range_index(1, 5);
    ptr_arr = ft_range_ptr(1, 5);
    put_int_arr(index_arr, 5 - 1);
    put_int_arr(ptr_arr, 5 - 1);
    free(ptr_arr);
    free(index_arr);
    return (0);
}

