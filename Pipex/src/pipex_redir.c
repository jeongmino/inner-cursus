/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:55:12 by junoh             #+#    #+#             */
/*   Updated: 2022/06/09 16:08:08 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

static	void	ft_pipe_to_outfile(t_info *info, int index)
{
	if (index % 2 == 1)
		ft_dup2(info->pipe_alpha[0], STDIN_FILENO);
	else
		ft_dup2(info->pipe_beta[0], STDIN_FILENO);
	return ;	
}

static void	ft_last_cmd(t_info *info)
{
	info->fdout = open_file(info->argv[info->argc - 1], STDOUT_FILENO);
	ft_dup2(info->fdout, STDOUT_FILENO);
	info->pid = ft_fork();
	if (info->pid)
		wait(NULL);
	else
		execute_cmd(info->argv[info->argc - 2], info->envp);
}

void    ft_redir(t_info *info)
{
	int i;

	ft_dup2(info->fdin, STDIN_FILENO);
	i = 2;
    info->flag = 1;
	while (i < info->argc - 2)
	{
		ft_make_pipe(info, i);
		info->pid = ft_fork();
		if (info->pid) // Parent's process
			ft_parent_proc(info, i);
		else
			ft_child_proc(info, i);   
		info->flag *= -1;
		i++;    
	}
	ft_pipe_to_outfile(info, i);
	ft_last_cmd(info);
}