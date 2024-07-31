/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:53:51 by charlie           #+#    #+#             */
/*   Updated: 2024/03/07 14:53:52 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node. Creates a new
// list resulting of the successive applications of
// the function ’f’. The ’del’ function is used to
// delete the content of a node if needed.

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result_lst;
	t_list	*result_lst_1st;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	result_lst = ft_lstnew(f(lst->content));
	if (result_lst == NULL)
	{
		ft_lstdelone(result_lst, del);
		return (NULL);
	}
	result_lst_1st = result_lst;
	lst = lst->next;
	while (lst)
	{
		result_lst->next = ft_lstnew(f(lst->content));
		if (result_lst->next == NULL)
		{
			ft_lstclear(&result_lst_1st, del);
			return (NULL);
		}
		result_lst = result_lst->next;
		lst = lst->next;
	}
	return (result_lst_1st);
}
