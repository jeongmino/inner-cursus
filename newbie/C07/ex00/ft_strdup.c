#include <stdlib.h>

int	ft_strlen(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup_index(char *str) // 인덱스 + 코드 줄 여유롭게
{
	char	*dup;
	int		i;

	dup = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char    *ft_strdup_pointer(char *str)
{
    char    *dup;
    char    *tmp;

    dup = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
    if (!dup)
        return(NULL);
    tmp = dup;
    while (*str)
        *tmp++ = *str++;
    *tmp = '\0';
    return (dup);
}

#include <stdio.h>
#include <string.h>

int     ft_strlen(char *str);
char	*ft_strdup_index(char *str);
char    *ft_strdup_pointer(char *str);

int main(void)
{
    char    *str = "apple";
    char    *dup_index;
    char    *dup_ptr;
    char    *origin;

    dup_index = ft_strdup_index(str);
    dup_ptr = ft_strdup_pointer(str);
    printf("origin : %s\n", str);
    printf("dup_index : %s\n", dup_index);
    printf("dup_ptr : %s\n", dup_ptr);
	system("leaks a.out");
    free(dup_index);
    free(dup_ptr);
}

