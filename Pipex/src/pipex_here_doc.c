/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:00:13 by junoh             #+#    #+#             */
/*   Updated: 2022/05/31 17:50:37 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void    ft_here_doc(t_info *info)
{
    char    *limiter;
    char    *buf;
    int     tmp_fd;
    
    limiter = ft_strndup(info->argv[2], ft_strlen(info->argv[2]));
    tmp_fd = open_file(".here_doc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0000644 )
    while (1)
    {
        write(1, "here_doc>", 9);
        buf = get_next_line(STDIN_FILENO);
        if (buf == NULL || !ft_strncmp(buf, limiter, ft_strlen(limiter)))
        {
            free(limiter);
            break;
        }
        write(info->pipe_here_doc)
        
    }
                    
}