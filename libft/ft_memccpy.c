/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:10:58 by elchouai          #+#    #+#             */
/*   Updated: 2018/10/13 00:18:19 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*str_src;
	unsigned char		*str_dest;
	size_t				i;
	void				*result;

	str_dest = dst;
	str_src = src;
	i = 0;
	while (i < n)
	{
		str_dest[i] = str_src[i];
		if (str_src[i] == (unsigned char)c)
		{
			result = (void *)&str_dest[i + 1];
			return (result);
		}
		i++;
	}
	return (NULL);
}
