/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 20:17:48 by elchouai          #+#    #+#             */
/*   Updated: 2018/10/16 20:38:31 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_insert_data(t_btree **root, void *item,
				int (*cmpf)(void *, void *))
{
	t_btree	*current;

	if (!root || !*root || !item)
	{
		if (item && root)
			*root = ft_btree_create_node(item);
		return ;
	}
	current = *root;
	if (cmpf(item, current->item) < 0)
	{
		if (current->left)
			ft_btree_insert_data(&current->left, item, cmpf);
		else
			current->left = ft_btree_create_node(item);
	}
	else
	{
		if (current->right)
			ft_btree_insert_data(&current->right, item, cmpf);
		else
			current->right = ft_btree_create_node(item);
	}
}
