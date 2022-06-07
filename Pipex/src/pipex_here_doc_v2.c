/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc_v2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:47:07 by junoh             #+#    #+#             */
/*   Updated: 2022/06/07 18:24:59 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

static void    ft_here_doc_gnl(t_info *info)
{
        char    *limiter;
        char    *buf;
        int     len;

        len = ft_strlen(info->argv[2]); 
        limiter = ft_strndup(info->argv[2], len);
        while (1)
        {
            write(STDERR_FILENO, "here_doc> ", 10);
            buf = get_next_line(STDIN_FILENO);
            if (buf == NULL ||(buf[len] == '\n' && \
                        !ft_strncmp(buf, limiter, len)))
            {
                free(limiter);
                free(buf);
                break ;
            }
            write(info->pipe_alpha[1], buf, ft_strlen(buf));
            free(buf);
        }
        return ;
}

static  void    ft_here_doc_append(t_info *info)
{
    info->fdout = open(info->argv[5], O_WRONLY | O_CREAT | O_APPEND, 0000644);
    ft_dup2(info->fdout, STDOUT_FILENO);
    ft_dup2(info->pipe_beta[0], STDIN_FILENO);
    ft_close(info->fdout);
    ft_close(info->pipe_beta[0]);
    execute_cmd(info->argv[4], info->envp);
    ft_put_cmd_err(info->argv[4]);
}
#include <stdio.h>
void    ft_here_doc_redir(t_info *info)
{
    ft_make_pipe(info, 0);
    ft_make_pipe(info, 1);
    ft_here_doc_gnl(info);
printf("here_doc_redir\n");
    info->pid = ft_fork();
    if (info->pid)
    {
        ft_close(info->pipe_alpha[0]);
        ft_close(info->pipe_alpha[1]);
        ft_close(info->pipe_beta[1]);
        waitpid(info->pid, NULL, WNOHANG);
    }
    else
    {
        ft_dup2(info->pipe_alpha[0], STDIN_FILENO);
        ft_close(info->pipe_alpha[0]);
        ft_dup2(info->pipe_beta[1], STDOUT_FILENO);
        ft_close(info->pipe_beta[1]);
        ft_close(info->pipe_beta[0]);
        execute_cmd(info->argv[3], info->envp);
        ft_put_cmd_err(info->argv[3]);
    }
    ft_here_doc_append(info);
    return ;
}