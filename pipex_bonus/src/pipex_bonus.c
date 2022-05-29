/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:35:11 by junoh             #+#    #+#             */
/*   Updated: 2022/05/29 19:40:31 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex_bonus.h"

void    ft_parent_proc(t_info *info, int index)
{
   if (info->flag == 1)
            {
                close(info->pipe_alpha[1]); // 1st parent's proc doesn't use write of pipe     
                close(info->pipe_beta[0]);
            }
            else
            {
                close(info->pipe_beta[1]);
                close(info->pipe_alpha[0]);
            }
            waitpid(info->pid, NULL, WNOHANG); 
}

void    ft_make_pipe(t_info *info, int index)
{
    if (index % 2 == 0)
        pipe(info->pipe_alpha);
    else
        pipe(info->pipe_beta);
    return ;
}

void    ft_redir(t_info *info)
{
    int i;

    dup2(info->fdin, STDIN_FILENO);
    i = 2;
    while (i < info->argc - 2)
    {
        ft_make_pipe(info, i);
        info->pid = fork();
        if (!info->pid) // Parent's process
        {
            if (info->flag == 1)
            {
                close(info->pipe_alpha[1]); // 1st parent's proc doesn't use write of pipe     
                close(info->pipe_beta[0]);
            }
            else
            {
                close(info->pipe_beta[1]);
                close(info->pipe_alpha[0]);
            }
            waitpid(info->pid, NULL, WNOHANG);
        }
        else
        {
            if (info->flag == 1) // if the number of cmd is even
            {
                close(info->pipe_alpha[0]);
                if (i != 2)
                    dup2(info->pipe_beta[0], STDIN_FILENO);
                dup2(info->pipe_alpha[1], STDOUT_FILENO);
                execute_cmd(info->argv[i], info->envp);
            }
            else
            {
                close(info->pipe_beta[0]);
                dup2(info->pipe_alpha[0], STDIN_FILENO);
                dup2(info->pipe_beta[1], STDOUT_FILENO);
                execute_cmd(info->argv[i], info->envp)
            }
        }
        info->flag *= -1;
        i++;    
    }
}


int main(int ac, char **av, char **env)
{
    t_info  info;
    int     i;
    
    if (argc < 5)
        write(STDERR_FILENO, "pipex: invaild arguments number\n", 32);	 
    else
    {
        info.fdin = open_file(argv[1], STDIN_FILENO);
        info.argc = ac;
        info.argv = av;
        info.envp = env;
        ft_redir(&info); 
        fdout = open_file(av[ac - 1], STDOUT_FILENO);
        dup2(fdout, STDOUT_FILENO);
        execute_cmd(av[ac - 2], envp);
        
    }
    return (0);
}