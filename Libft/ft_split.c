/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:01:08 by junoh             #+#    #+#             */
/*   Updated: 2022/01/04 19:34:22 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	if (*s != c && *s != '\0')
		cnt++;
	while (*s)
	{
		if ((*s == c) && (*(s + 1) != c) && \
			(*(s + 1) != '\0'))
			cnt++;
		s++;
	}
	return (cnt);
}

static	void	*ft_strfree(char **strs, int stridx)
{
	int	i;

	i = 0;
	while (i < stridx)
		free(strs[i++]);
	free(strs);
	return (NULL);
}

static	char	**ft_split2(char **strs, char const *s, char c, int cnt)
{
	int		len ;
	int		stridx;
	char	*buf;

	stridx = 0;
	while (stridx < cnt)
	{
		len = 0;
		while (*s != '\0' && *s == c)
			s++;
		while (*s != '\0' && *s != c)
		{
			len++;
			s++;
		}
		strs[stridx] = (char *)malloc(sizeof(char) * (len + 1));
		if (strs[stridx] == NULL)
			return (ft_strfree(strs, stridx));
		buf = (char *)s - len;
		ft_strlcpy(strs[stridx], buf, len + 1);
		stridx++;
	}
	strs[stridx] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		wc;

	if (s == NULL)
		return (NULL);
	wc = ft_count(s, c);
	strs = (char **)malloc(sizeof(char *) * (wc + 1));
	if (strs == NULL)
		return (NULL);
	strs = ft_split2(strs, s, c, wc);
	return (strs);
}
