/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:23:04 by junoh             #+#    #+#             */
/*   Updated: 2022/05/28 19:5 by4 junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

static char	*get_path(char **envp, char *cmd)
{
	char	*path;
	char	**real_path;
	int		i;

	i = 0;
	while (envp[i] != NULL && (ft_strncmp(envp[i], "PATH=", 5)))
		i++;
	if (envp[i] == NULL)
		exit(1);
	path = ft_strndup(envp[i] + 5, ft_strlen(envp[i]) - 5);
	real_path = ft_split(path, ':');
	i = 0;
	while (real_path[i] != NULL)
	{
		path = ft_path_join(real_path[i++], cmd);
		if (access(path, F_OK) == 0)
		{
			ft_frees(real_path);
			return (path);
		}
	}
	ft_frees(real_path);
	return (cmd);
}

void	execute_cmd(char *cmd, char **envp)
{
	char	*excute_path;
	char	**args;

	args = ft_split(cmd, ' ');
	if (args[0][0] == '/')
		excute_path = args[0];
	else
		excute_path = get_path(envp, args[0]);
	execve(excute_path, args, envp);
	ft_put_cmd_err(cmd);
}