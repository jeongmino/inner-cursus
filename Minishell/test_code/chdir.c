#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char *dir;
	char *tmp;
	int		ret;

	dir = (char*)malloc(400);
	tmp = getcwd(dir, 400);
	//printf("tmp_pwd = %s\n", tmp);a
	printf("%s\n", getenv("PWD"));
	ret = chdir("/Users/junoh/Desktop/inner-cursus/Minishel");
	ret = chdir("asd");
	getcwd(dir, 400);
	printf("after_chdir = %s\n", dir);
	printf("ret = %d\n", ret);
//	printf("%s\n", getenv("PWD"));
	free(dir);
}
