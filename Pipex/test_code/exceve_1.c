/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceve_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 21:38:46 by junoh             #+#    #+#             */
/*   Updated: 2022/06/14 15:05:54 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av, char **envp)
{
	char	*arr[] = {"ls", "-", NULL};
	int		ret = execve("/bin/ls", arr, envp);
	if (ret == -1)
		write(1, "bugbug\n", 7);
	return (0);
}
