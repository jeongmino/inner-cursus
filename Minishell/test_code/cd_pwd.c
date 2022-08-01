#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	pwd(char *p_path)
{
	char *pwd;

	pwd = getcwd(NULL, 0);
	printf("pwd = %s\n", pwd);
	printf("p_path = %s\n", p_path);
	free(pwd);
	return (0);
}

int	cd(char *path, char *p_path)
{
	chdir(getenv(path));
	pwd(p_path);
	printf("cd\n");
   	printf("p_path = %s\n", p_path);	
	return (0);
}

int	main(void)
{
	char p_path[999];

	getcwd(p_path, 999);
	pwd(p_path);
	cd("HOME", p_path);
}

