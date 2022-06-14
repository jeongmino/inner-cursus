/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:47:07 by junoh             #+#    #+#             */
/*   Updated: 2022/06/14 15:18:43 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"
#include <stdio.h>

static void    ft_here_doc_gnl(t_info *info)
{
        char    *limiter;
        char    *buf;
        int     len;

        len = ft_strlen(info->argv[2]); 
        limiter = ft_strndup(info->argv[2], len);
        while (1)
        {
            write(STDOUT_FILENO, "here_doc> ", 10);
            buf = get_next_line(STDIN_FILENO);
            if (buf == NULL || (ft_strlen(buf) == len && \
                !ft_strncmp(buf, limiter, len)))
            {
                free(limiter);
                free(buf);
                break ;
            }
            buf = str_join(buf, "\n");
            write(info->pipe_alpha[1], buf, ft_strlen(buf));
            free(buf);
        }
        return ;
}

static  void    ft_here_doc_append(t_info *info)
{
    info->fdout = open(info->argv[5], O_WRONLY | O_CREAT | O_APPEND, 644);
    info->pid = ft_fork();
    if (info->pid)
        wait(NULL);
    else
    {
        ft_dup2(info->fdout, STDOUT_FILENO);
        ft_dup2(info->pipe_beta[0], STDIN_FILENO);
        execute_cmd(info->argv[4], info->envp);
    }
    return ;
}
void    ft_here_doc_redir(t_info *info)
{
    ft_make_pipe(info, 0);
    ft_make_pipe(info, 1);
    ft_here_doc_gnl(info);
    info->pid = ft_fork();
    if (info->pid != 0)
    {
        close(info->pipe_alpha[0]);
        close(info->pipe_alpha[1]);
        close(info->pipe_beta[1]);
        ft_here_doc_append(info);
        wait(&info->status);
        printf("%d\n", WEXITSTATUS(info->status));
        printf("%d\n", WTERMSIG(info->status));
    }
    else
    {
        ft_dup2(info->pipe_alpha[0], STDIN_FILENO);
        ft_dup2(info->pipe_beta[1], STDOUT_FILENO);
        close(info->pipe_beta[0]);
        close(info->pipe_alpha[1]);
        execute_cmd(info->argv[3], info->envp);
    }
    return ;
}