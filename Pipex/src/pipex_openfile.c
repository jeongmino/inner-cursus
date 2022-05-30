/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_openfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:56:39 by junoh             #+#    #+#             */
/*   Updated: 2022/05/30 20:54:40 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	open_file(char *file, int flag)
{
	int	open_ret;
	
	if (flag == 0)
	{
		if (access(file, F_OK != 0))
		{
			write(STDERR_FILENO, "pipex: ", 7);
			write(STDERR_FILENO, file, ft_strlen(file));
			write(STDERR_FILENO, ": No such file or directory\n", 28);
			return (0);
		}
		open_ret = open(file, O_RDONLY);
		if (open_ret < 0)
			exit(127);
		return (open_ret);
	}
	open_ret = open(file, O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (open_ret < 0)
		exit(127);
	return (open_ret);
}