/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:35:11 by junoh             #+#    #+#             */
/*   Updated: 2022/05/31 15:51:22 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int main(int ac, char **av, char **env)
{
	t_info  info;
	
	if (ac < 5)
		write(STDERR_FILENO, "pipex: invaild arguments number\n", 32);	 
	else
	{
		info.argc = ac;
		info.argv = av;
		info.envp = env
		if (!ft_strncmp(av[1], "here_doc", 8))
		{
			ft_here_doc(info);
			return (0);
		}
		info.fdin = open_file(av[1], STDIN_FILENO);
		ft_redir(&info); 
		info.fdout = open_file(av[ac - 1], STDOUT_FILENO);
		ft_dup2(info.fdout, STDOUT_FILENO);
		execute_cmd(av[ac - 2], env);
	}
	return (0);
}