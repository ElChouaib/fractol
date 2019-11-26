/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 17:06:49 by elchouai          #+#    #+#             */
/*   Updated: 2018/10/15 19:52:44 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*temp;
	t_list	*made;

	if (!lst)
		return (NULL);
	made = (*f)(lst);
	result = made;
	temp = result;
	lst = lst->next;
	while (lst != NULL)
	{
		made = (*f)(lst);
		temp->next = made;
		temp = temp->next;
		lst = lst->next;
	}
	return (result);
}
