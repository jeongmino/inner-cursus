/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:55:12 by junoh             #+#    #+#             */
/*   Updated: 2022/05/29 21:02:49 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void    ft_redir(t_info *info)
{
	int i;

	dup2(info->fdin, STDIN_FILENO);
	i = 2;
    info->flag = 1;
	while (i < info->argc - 2)
	{
		ft_make_pipe(info, i);
		info->pid = fork();
		if (info->pid) // Parent's process
			waitpid(info->pid, NULL, WNOHANG);
		else
			ft_child_proc(info, i);   
		info->flag *= -1;
		i++;    
	}
    return ;
}