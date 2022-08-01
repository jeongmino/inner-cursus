#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_pwd(char *cmd)
{
	char *str;

	(void)cmd;
	str = getcwd(NULL, 0);
	if (str == NULL)
		return (-1);
	else
	{
		printf("%s\n", str);
		free(str);
	}
	return (0);
}

int	main(void)
{
	char *cmd = NULL;

	if (!ft_pwd(cmd))
		printf("success\n");
	return (0);
}
