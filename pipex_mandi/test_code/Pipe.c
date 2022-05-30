/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:50:52 by junoh             #+#    #+#             */
/*   Updated: 2022/05/21 21:38:26 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

#define P_READ		0
#define P_WRITE		1
#define BUFFER_SIZE	4096

void childcommand(int fd)
{
	int	ret;
	char	buffer[BUFFER_SIZE];

	ret = read(fd, buffer, BUFFER_SIZE);
	buffer[ret] = '\0';
	write(STDOUT_FILENO, buffer, strlen(buffer));
	close(fd);
}

void childproc(int pipe[2])
{
	int	fd;
//	int	r_fd;
//	int	w_fd;

	printf("Child: I'm going to close fd for Read\n");
	printf("Child: I'm going to connect STDOUT to fd for Write\n");
	printf("Child: I'm going to connect STDIN to fd from a file\n");
	printf("Child: Eventually I'll read from STDIN (file) and write to STDOUT (pipe)\n");
	close(pipe[P_READ]);
//	w_fd = dup2(pipe[P_WRITE], STDOUT_FILENO);
//	close(pipe[P_WRITE]);
//	if (w_fd == -1)
//		exit(1);
	fd = open("read.txt", O_RDONLY);
	if (fd == -1)
		exit(1);
//	r_fd = dup2(fd, STDIN_FILENO);
//	close(fd);
//	if (r_fd == -1)
//		exit(1);
	childcommand(fd, pipe[P_WRITE]);
}

void parentcommand(void)
{
	int	ret;
	char	buffer[BUFFER_SIZE];

	ret = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	buffer[ret] = '\0';
	write(STDOUT_FILENO, buffer, strlen(buffer));
}

void parentproc(int pipe[2], pid_t pid)
{
	int	fd;
	int	r_fd;
	int	w_fd;

	printf("Parent: I'm going to close fd for Write\n");
	printf("Parent: I'm going to connect STDIN to fd for Read\n");
	printf("Parent: I'm going to connect STDOUT to fd from a file\n");
	printf("Parent: Eventually I'll read from STDIN (pipe) and write to STDOUT (file)\n");
	close(pipe[P_WRITE]);
	r_fd = dup2(pipe[P_READ], STDIN_FILENO);
	close(pipe[P_READ]);
	if (r_fd == -1)
		exit(1);
	fd = open("write.txt", O_WRONLY);
	if (fd == -1)
		exit(1);
	w_fd = dup2(fd, STDOUT_FILENO);
	if (w_fd == -1)
		exit(1);
	if (waitpid(pid, NULL, 0) == -1)
		exit(1);
	parentcommand();
}

int	main(void)
{
	int	fd[2];
	pid_t pid;

	if (pipe(fd) == -1)
		return (1);
	printf("Parent: fd for Read is %d, fd for Write is %d\n", fd[P_READ], fd[P_WRITE]);
	pid = fork();
	if (pid == -1)
	{
		close(fd[P_READ]);
		close(fd[P_WRITE]);
		return (1);
	}
	else if (!pid)
		childproc(fd);
	else
		parentproc(fd, pid);
	return (0);
}

