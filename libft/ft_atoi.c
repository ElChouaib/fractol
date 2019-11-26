/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:40:41 by elchouai          #+#    #+#             */
/*   Updated: 2018/10/16 20:05:29 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static void	determine_sign(const char *str, int *sign, int *i)
{
	if (str[*i] == '-')
	{
		*sign = -1;
		*i = *i + 1;
	}
	else if (str[*i] == '+')
	{
		*sign = 1;
		*i = *i + 1;
	}
}

int			ft_atoi(const char *str)
{
	int i;
	int result;
	int sign;

	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
		i++;
	sign = 1;
	determine_sign(str, &sign, &i);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}
