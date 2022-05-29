/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_make_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:54:16 by junoh             #+#    #+#             */
/*   Updated: 2022/05/29 20:18:47 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void    ft_make_pipe(t_info *info, int index)
{
	if (index % 2 == 0)
		pipe(info->pipe_alpha);
	else
		pipe(info->pipe_beta);
	return ;
}