/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:19:54 by junoh             #+#    #+#             */
/*   Updated: 2022/02/05 21:32:37 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

char	*ft_save_point(char *left_string_buf);

char	*ft_strchr(char *s, int c);

char	*ft_strjoin(char *left_string_buf, char *read_buf);

char	*ft_get_line_nl(char *left_string_buf, char *read_buf, int fd);

char	*ft_get_full_line(char *left_string_buf);

int		ft_strlen(char *s);

#endif
