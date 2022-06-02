#include <stdlib.h>

int	ft_strlen(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup_index(char *str)
{
	char	*tmp;
	int		i;

	tmp = (char)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
