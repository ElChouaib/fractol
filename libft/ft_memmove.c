/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:30:12 by elchouai          #+#    #+#             */
/*   Updated: 2018/10/16 22:40:06 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str_src;
	char	*str_dst;
	size_t	i;

	str_src = (char *)src;
	str_dst = (char *)dst;
	if (str_src < str_dst)
	{
		len -= 1;
		while ((int)(len) >= 0)
		{
			str_dst[len] = str_src[len];
			len--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			str_dst[i] = str_src[i];
			i++;
		}
	}
	return (dst);
}
