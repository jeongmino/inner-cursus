/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:34:11 by junoh             #+#    #+#             */
/*   Updated: 2022/05/30 20:54:57 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

pid_t   ft_fork(void)
{
    pid_t ret_pid;
    
    ret_pid = fork();
    if (ret_pid < 0)
        exit(127);
    return (ret_pid);
}

int ft_dup2(int fd1, int fd2)
{
    int ret_value;

    ret_value = dup2(fd1, fd2);
    if (ret_value < 0)
        exit(127);
    return (ret_value);
}

int ft_close(int fd)
{
    int ret_value;

    ret_value = close(fd);
    if (ret_value < 0)
        exit(127);
    return (ret_value);
}