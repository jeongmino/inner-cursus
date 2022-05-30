/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child_proc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:52:19 by junoh             #+#    #+#             */
/*   Updated: 2022/05/30 20:44:43 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void    ft_child_proc(t_info *info, int index)
{
    int i;

    i = index;
	if (info->flag == 1) // if the number of cmd is even
	{
		ft_close(info->pipe_alpha[0]);
		if (i != 2)
        {
			ft_dup2(info->pipe_beta[0], STDIN_FILENO);
            ft_close(info->pipe_beta[0]);
        }
		ft_dup2(info->pipe_alpha[1], STDOUT_FILENO);
        ft_close(info->pipe_alpha[1]);
		execute_cmd(info->argv[i], info->envp);
	}
	else
	{
		ft_close(info->pipe_beta[0]);
		ft_dup2(info->pipe_alpha[0], STDIN_FILENO);
		ft_dup2(info->pipe_beta[1], STDOUT_FILENO);
        ft_close(info->pipe_alpha[0]);
        ft_close(info->pipe_beta[1]);
		execute_cmd(info->argv[i], info->envp);
	}
    return ;
}