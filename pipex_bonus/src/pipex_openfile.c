/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_openfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:56:39 by junoh             #+#    #+#             */
/*   Updated: 2022/05/29 19:57:02 by junoh            ###   ########.fr       */
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