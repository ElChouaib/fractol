/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 23:06:59 by elchouai          #+#    #+#             */
/*   Updated: 2018/10/16 19:57:23 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*backup_itoa(char *str, int n, int len)
{
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	while (n)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		len;
	int		n_tmp;
	char	*str;

	len = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648\0"));
	if (n == 0)
		return (ft_strdup("0\0"));
	n_tmp = n;
	while (n_tmp)
	{
		n_tmp /= 10;
		len += 1;
	}
	if (n < 0)
		len += 1;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	str = backup_itoa(str, n, len - 1);
	return (str);
}
