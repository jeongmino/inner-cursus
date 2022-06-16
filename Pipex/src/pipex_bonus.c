/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:35:11 by junoh             #+#    #+#             */
/*   Updated: 2022/06/15 21:01:15 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"
#include <stdio.h>

static	void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len--)
		*ptr++ = (unsigned char)c;
	return (b);
}

int	main(int ac, char **av, char **env)
{
	t_info	info;
	int		ret;

	ret = 0;
	if (ac < 5)
		ft_error(ARGS_NUM_ERR);
	else
	{
		ft_memset(&info, 0, sizeof(t_info));
		info.argc = ac;
		info.argv = av;
		info.envp = env;
		if (!ft_strncmp(av[1], "here_doc", 8))
		{
			if (ac == 6)
				ft_here_doc_redir(&info);
			else
				ft_error(ARGS_NUM_ERR);
		}
		info.fdin = open_file(av[1], STDIN_FILENO);
		ret = ft_redir(&info);
	}
	return (ret);
}
