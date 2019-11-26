/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:14:08 by elchouai          #+#    #+#             */
/*   Updated: 2018/10/16 12:06:44 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*temp;

	temp = malloc(sizeof(char) * (size + 1));
	if (!temp)
		return (NULL);
	ft_memset(temp, '\0', size + 1);
	return (temp);
}
