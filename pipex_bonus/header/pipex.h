/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:18:12 by junoh             #+#    #+#             */
/*   Updated: 2022/05/29 20:41:23 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_info
{
	int		fdin;
	int		fdout;
    int		argc;
	char	**argv;
	char	**envp;
	int		pipe_alpha[2];
	int		pipe_beta[2];
	pid_t	pid;
	int		flag;
}				t_info;

int	    open_file(char *file, int flag);

void	execute_cmd(char *cmd, char **envp);

void	ft_redir(t_info *info);

void    ft_child_proc(t_info *info, int index);

void    ft_make_pipe(t_info *info, int index);

// void    ft_parent_proc(t_info *info);

int	    ft_strlen(char *str);

int	    ft_strichr(const char *s, int c);

int	    ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strndup(const char *s, int cpy_len);

char	*ft_path_join(char *left_string_buf, char *read_buf);

char	**ft_split(char const *s, char c);

void    ft_frees(char **str);



#endif
