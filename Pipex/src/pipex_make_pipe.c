/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_make_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:54:16 by junoh             #+#    #+#             */
/*   Updated: 2022/06/03 17:55:44 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void    ft_make_pipe(t_info *info, int index)
{
	int	pipe_ret;

	if (index == -1)
	{
		pipe_ret = pipe(info->pipe_here_doc);
		if (pipe_ret < 0)
			exit(127);
	}
	else if (index % 2 == 0)
	{
		pipe_ret = pipe(info->pipe_alpha);
		if (pipe_ret < 0)
			exit(127);
	}
	else
	{
		pipe_ret = pipe(info->pipe_beta);
		if (pipe_ret < 0)
			exit(127);
	}
	return ;
}