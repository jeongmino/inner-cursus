/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:23:04 by junoh             #+#    #+#             */
/*   Updated: 2022/05/25 00:43:50 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	open_file(char *file, int flag)
{
	if (flag == 0)
	{
		if (access(file, F_OK != 0))
		{
			write(STDERR_FILENO, "pipex: ", 7);
			write(STDERR_FILENO, file, ft_strlen(file));
			write(STDERR_FILENO, ": No such file or directory\n", 28);
			return (0);
		}
		return (open(file, O_RDONLY));
	}
	return (open(file, O_TRUNC | O_CREAT | O_RDWR, 0000644));
}

char	*get_path(char **envp, char **cmd_args)
{
	char	*path;
	char	*real_path;
	int		i;

	if (ft_strchr(cmd_args[0], '/') == 0)
		return (cmd_args[0])
	i = 0;
	while (envp[i] != NULL && (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	path = ft_strdup(path, envp[i]);
	while (path != NULL)
	{
		
	}
}

void	execute_cmd(char **cmd, char **envp)
{
	char	**excute_path;
	char	**args;

	args = ft_split(cmd, ' ');
	excute_path = (envp, args);
	execve(excute_path, args, 0);
	write(STDERR_FILENO, "pipex: ", 7);
	write(STDERR_FILENO, cmd, ft_strlen(cmd));
	write(STDERR_FILENO, ": command not found\n", 20);
	exit(127);
}

void	make_redir(char **cmd, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	pipe(pipefd);
	pid = fork();
	if (pid != 0) // parent's precess
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FIELNO);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		exec(cmd, envp);
	}
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	int	fdin;
	int	fdout;

	if (argc == 5)
	{
		fdin = open_file(argv[1], 0);
		if (fdin == STDIN_FILENO)
			return (0);
		fdout = open_file(argv[4], 1);
		dup2(fdin, STDIN_FILENO); // infile의 fd가 표준 입력으로 바꿈
		dup2(fdout, STDOUT_FILENO); // outfile의 fd가 표준 출력으로 바꿈
		make_redir(argv[2], envp);
		exec(argv[3], envp);
	}
	return (0);
}
