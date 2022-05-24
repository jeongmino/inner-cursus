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
	return (access, O_TRUNC | O_CREAT | O_RDWR, 0000644);
}

int	main(int argc, char **argv, char **envp)
{
	int	fdin;
	int	fdout;

	if (argc == 5)
	{
		fdin = open_file(argv[0], 0);
		if (fdin == STDIN_FILENO)
			return (0);
		fdout = open_file(argv[4], 1);
	}
	return (0);
}
