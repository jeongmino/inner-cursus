/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_put_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 22:23:19 by junoh             #+#    #+#             */
/*   Updated: 2022/06/14 17:33:16 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}

static void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		ft_putchar_fd(*str++, fd);
	return ;
}

void	ft_error(int err)
{
	if (err == ARGS_NUM_ERR)
		ft_putstr_fd("Invalid number of arguments!", 2);
	else if (err == PID_ERR)
		ft_putstr_fd("Invalid pid", 2);
	else if (err == PIPE_ERR)
		ft_putstr_fd("Pipe failed", 2);
	exit(1);
}

int	ft_perror(int err)//ft_perror(CMD_ERR, 127);
{
	if (err == INFILE_OPEN_ERR) // err_num == 1
	{	
		perror("Infile open error!");
		exit(127);
	}
	else if (err == OUTFILE_OPEN_ERR) //err_num == 1 
		perror("Outfile open error!"); 
	else if (err == EXE_ERR)  // 명령어가 존재하지 않으면 1  
		perror("Execve error!");     
	else if (err == PATH_ERR) // execve retrun == -1 일때 err_num == 0
	{	
		perror("command not found");
		exit(127);
	}
	else if (err == DUP_ERR) // badfile discriptor 일때 err_num == 1
		perror("Dupplitcate error"); 
	exit(1);
}

int	ft_check_status(t_info *info)
{
	const int	w_status = info->status & 177;
	
	if (w_status == 0)
		return ((info->status >> 8) & 0x000000ff);
	if (w_status != 177 && w_status != 0)
		return (w_status);
	return (0);
}