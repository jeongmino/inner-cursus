/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:00:13 by junoh             #+#    #+#             */
/*   Updated: 2022/06/01 22:28:19 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

static  void    ft_here_doc_append(t_info *info, int tmp_fd)
{
    info->fdout = open_file(info->argv[5], O_WRONLY | O_CREAT | O_APPEND, 0000644);
    ft_dup2(info->fdout, STDOUT_FILENO);
    ft_dup2(tmp_fd, STDIN_FILENO);
    ft_close(info->fdout);
    ft_close(tmp_fd);
    execute_cmd(info->argv[4], info->envp);
    ft_put_cmd_err(info->argv[4]);
}

static  void    ft_here_doc_redir(t_info *info, int tmp_fd)
{
    pid_t   pid;

    ft_dup2(fd, STDIN_FILENO);
    ft_close(fd);
    pid = ft_fork();
    if (pid)
    {
        ft_close(info->pipe_here_doc[1]);
        waitpid(pid, NULL, WNOHANG);   
    }
    else
    {
        ft_close(info->pipe_here_doc[0]);
        ft_dup2(info->pipe_here_doc[1], STDOUT_FILENO);
        ft_close(info->pipe_here_doc[1]);
        execute_cmd(info->argv[3], info->envp);
    }
    ft_here_doc_append(info, tmp_fd);
    return ;
}

void    ft_here_doc(t_info *info)
{
    char    *limiter;
    char    *buf;
    int     tmp_fd;
    
    limiter = ft_strndup(info->argv[2], ft_strlen(info->argv[2]));
    tmp_fd = open_file(".here_doc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
    while (1)
    {
        write(1, "here_doc>", 9);
        buf = get_next_line(STDIN_FILENO);
        if (buf == NULL || !ft_strncmp(buf, limiter, ft_strlen(limiter)))
        {
            free(limiter);
            free(buf);
            break;
        }
        write(tmp_fd, buf, ft_strlen(buf));
    }
    ft_make_pipe(info->pipe_here_doc);
    ft_here_doc_redir(info, tmp_fd);    
}