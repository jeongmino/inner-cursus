#include <stdlib.h>

int ft_strlen(char  *str)
{
    int len;

    len = 0;
    while (str[len] != '\0')
        len++;
    return (len);
}

int ft_str_count(char **strs, int size)
{
    int cnt;

    cnt = 0;
    while (size-- > 0)
        cnt += ft_strlen(strs[size]);
    return (cnt);
}

char    *ft_strjoin(int size, char **strs, char *sep)
{
    char    *joined_str;
    int     i;
    int     j;
    int     k;

    joined_str = (char *)malloc((ft_str_count(strs, size) + (size - 1) * \
                 ft_strlen(sep) + 1) * sizeof(char)); // null terminate와 sep 개수 고려
    if (joined_str == NULL)
        return (NULL);
    i = 0;
    while (i < size)
    {
        j = 0;
        while (strs[i][j] != '\0')
            joined_str[k++] = strs[i][j++];
        j = 0;
        if (i != size - 1)
        {
            while (sep[j] != '\0')
                joined_str[k++] = sep[j++];
        }
        i++;
    }
    joined_str[k] = '\0';
    return (joined_str);
}

char    *ft_strjoin_ptr(int size, char **strs, char *sep)
{
    char    *joined_str;
    char    *tmp;
    char    *sep_tmp;
    char    *strs_tmp;
   
    joined_str = (char *)malloc((ft_str_count(strs, size) + (size - 1) * \
                 ft_strlen(sep) + 1) * sizeof(char)); // null terminate와 sep 개수 고려
    if (joined_str == NULL)
        return (NULL);
    tmp = joined_str;
    while (size-- > 0)
    {
        strs_tmp = *strs++;
        while (*strs_tmp != '\0')
            *tmp++ = *strs_tmp++;
        if (size != 0)
        {
            sep_tmp = sep;
            while (*sep_tmp != '\0')
                *tmp++ = *sep_tmp++;
        }
    }
    *tmp = '\0';
    return (joined_str);
}

#include <stdio.h>

int main(void)
{
    char    *strs[5] = {"apple", "banana", "grape", "cat", "dog"};

    printf("%s\n", ft_strjoin(5, strs, ", "));
    printf("%s\n", ft_strjoin_ptr(5, strs, ", "));
    return (0);
}
