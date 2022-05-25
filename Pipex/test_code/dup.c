#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	char *argv[2];
	int	fdin;
	int	fdout;

	fdin = open("input", O_RDONLY);
	fdout = open("output", O_WRONLY);
	dup2(fdout, STDOUT_FILENO);
	dup2(fdin, STDIN_FILENO);
	argv[0] = "cat";
	argv[1] = 0;
	execve("/bin/cat", argv, 0);
}

