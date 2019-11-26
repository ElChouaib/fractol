/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 20:15:19 by elchouai          #+#    #+#             */
/*   Updated: 2018/10/16 20:34:03 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root->left)
		ft_btree_apply_infix(root->left, applyf);
	applyf(root->item);
	if (root->right)
		ft_btree_apply_infix(root->right, applyf);
}
