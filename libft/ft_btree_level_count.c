/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_level_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 20:18:25 by elchouai          #+#    #+#             */
/*   Updated: 2018/10/16 20:35:50 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	max(int a, int b)
{
	return (a > b ? a : b);
}

int			ft_btree_level_count(t_btree *root)
{
	int	count;

	count = 0;
	if (!root)
		return (0);
	if (root->left)
		count = max(count, ft_btree_level_count(root->left));
	if (root->right)
		count = max(count, ft_btree_level_count(root->right));
	return (count + 1);
}
