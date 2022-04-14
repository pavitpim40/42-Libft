/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 01:47:25 by ppimchan          #+#    #+#             */
/*   Updated: 2022/04/03 01:47:38 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new_lst;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (NULL);
	tmp = new_lst;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew(f(lst->content));
		if (!tmp->next)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new_lst);
}
