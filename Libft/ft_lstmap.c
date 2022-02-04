/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:09:13 by junoh             #+#    #+#             */
/*   Updated: 2021/12/22 12:32:10 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*newlist;

	list = NULL;
	if (f == NULL || lst == NULL)
		return (list);
	while (lst != NULL)
	{
		newlist = ft_lstnew(f(lst->content));
		if (newlist == NULL)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&list, newlist);
		lst = lst->next;
	}
	return (list);
}
