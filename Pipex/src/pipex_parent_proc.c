/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parent_proc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:51:14 by junoh             #+#    #+#             */
/*   Updated: 2022/06/14 16:19:02 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void    ft_parent_proc(t_info *info, int index)
{
	if (info->flag == 1)
	{
		close(info->pipe_alpha[1]); // 1st parent's proc doesn't use write of pipe     
		if (index != 2)
			close(info->pipe_beta[0]);
	}
	else
	{
		close(info->pipe_beta[1]);
		close(info->pipe_alpha[0]);
	}
    return ;
}