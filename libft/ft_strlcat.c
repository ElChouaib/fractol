/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:08:34 by elchouai          #+#    #+#             */
/*   Updated: 2018/10/12 16:44:39 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		size_dst;
	size_t		size_src;

	i = 0;
	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (size < size_dst + 1)
		return (size + size_src);
	while (size_dst + i < size - 1 && src[i] != '\0')
	{
		dst[size_dst + i] = src[i];
		i++;
	}
	dst[size_dst + i] = '\0';
	return (size_dst + size_src);
}
