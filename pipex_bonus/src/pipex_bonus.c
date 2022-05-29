/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:35:11 by junoh             #+#    #+#             */
/*   Updated: 2022/05/29 20:18:38 by junoh            ###   ########.fr       */
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
		info.fdin = open_file(av[1], STDIN_FILENO);
		info.argc = ac;
		info.argv = av;
		info.envp = env;
		ft_redir(&info); 
		info.fdout = open_file(av[ac - 1], STDOUT_FILENO);
		dup2(info.fdout, STDOUT_FILENO);
		execute_cmd(av[ac - 2], env);
	}
	return (0);
}