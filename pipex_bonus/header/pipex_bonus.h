/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:24:57 by junoh             #+#    #+#             */
/*   Updated: 2022/05/29 17:40:02 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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

char	*get_path(char **envp, char *cmd);

void	execute_cmd(char *cmd, char **envp);

void	make_redir(char *cmd, char **envp);

int	    main(int argc, char **argv, char **envp);

int	    ft_strlen(char *str);

int	    ft_strichr(const char *s, int c);

int	    ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strndup(const char *s, int cpy_len);

char	*ft_path_join(char *left_string_buf, char *read_buf);

char	**ft_split(char const *s, char c);

void    ft_frees(char **str);

#endif
