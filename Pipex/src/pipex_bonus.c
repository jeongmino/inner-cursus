/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:35:11 by junoh             #+#    #+#             */
/*   Updated: 2022/06/07 17:22:07 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"
#include <stdio.h>

int main(int ac, char **av, char **env)
{
	t_info  info;
	
	if (ac < 5)
		perror("pipex: invaild arguments number\n");
	else
	{
		info.argc = ac;
		info.argv = av;
		info.envp = env;
		if (!ft_strncmp(av[1], "here_doc", 8))
		{
			ft_here_doc_redir(&info);
			return (0);
		} 
		info.fdin = open_file(av[1], STDIN_FILENO);
		ft_redir(&info); 
		info.fdout = open_file(av[ac - 1], STDOUT_FILENO);
		ft_dup2(info.fdout, STDOUT_FILENO);
		close(info.fdout);
		execute_cmd(av[ac - 2], env);
	}
	return (0);
}