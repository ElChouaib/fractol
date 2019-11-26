/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 20:17:59 by elchouai          #+#    #+#             */
/*   Updated: 2018/10/16 20:34:50 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_create_node(void *item)
{
	t_btree *tree;

	tree = (t_btree *)malloc(sizeof(t_btree));
	if (tree)
	{
		tree->item = item;
		tree->left = 0;
		tree->right = 0;
	}
	return (tree);
}
