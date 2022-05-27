/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:23:04 by junoh             #+#    #+#             */
/*   Updated: 2022/05/27 18:02:33 by junoh            ###   ########.fr       */
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

char	*get_path(char **envp, char *cmd)
{
	char	*path;
	char	**real_path;
	int		i;

	i = 0;
	while (envp[i] != NULL && (ft_strncmp(envp[i], "PATH=", 5)))
		i++;
	if (envp[i] == NULL)
		exit(1);
	path = ft_strndup(envp[i] + 5, ft_strlen(envp[i]) - 5);
	real_path = ft_split(path, ':');
	i = 0;
	while (real_path[i] != NULL)
	{
		path = ft_path_join(real_path[i++], cmd);
		if (access(path, F_OK) == 0)
		{
			ft_frees(real_path);
			return (path);
		}
	}
	ft_frees(real_path);
	return (cmd);
}

void	execute_cmd(char *cmd, char **envp)
{
	char	*excute_path;
	char	**args;

	args = ft_split(cmd, ' ');
	if (args[0][0] == '/' )
		excute_path = args[0];
	else
		excute_path = get_path(envp, args[0]);
	execve(excute_path, args, envp);
	write(STDERR_FILENO, "pipex: ", 7);
	write(STDERR_FILENO, cmd, ft_strlen(cmd));
	write(STDERR_FILENO, ": command not found\n", 20);
	exit(127);
}

void	make_redir(char *cmd, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	pipe(pipefd);
	pid = fork();
	if (pid != 0) // parent's precess
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		waitpid(pid, NULL, WNOHANG);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		execute_cmd(cmd, envp);
	}
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	int	fdin;
	int	fdout;
	int	i;

	if (argc >= 5)
	{;
		fdin = open_file(argv[1], 0);
		if (fdin == STDIN_FILENO)
			return (0);
		fdout = open_file(argv[4], 1);
		dup2(fdin, STDIN_FILENO); // infile의 fd가 표준 입력으로 바꿈
		dup2(fdout, STDOUT_FILENO); // outfile의 fd가 표준 출력으로 바꿈
		i = 2;
		while (i < argc - 2)
			make_redir(argv[i++], envp);
		execute_cmd(argv[i], envp);
		system("leaks pipex");
	}
	else
		write(STDERR_FILENO, "pipex: invaild arguments number\n", 32);	
	return (0);
}
