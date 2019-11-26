/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 11:37:02 by elchouai          #+#    #+#             */
/*   Updated: 2018/11/09 17:18:38 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *temp;

	temp = malloc(sizeof(temp) * size);
	if (!temp)
		return (NULL);
	else
	{
		ft_bzero(temp, size);
		return (temp);
	}
}
