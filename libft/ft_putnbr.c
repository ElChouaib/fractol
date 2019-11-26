/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:44:51 by elchouai          #+#    #+#             */
/*   Updated: 2018/10/15 14:44:54 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	if (nb >= 0 && nb < 10)
	{
		ft_putchar(nb + '0');
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (nb > -10)
	{
		ft_putchar('-');
		ft_putchar(-1 * nb + '0');
	}
	else
	{
		ft_putchar('-');
		ft_putnbr(-1 * (nb / 10));
		ft_putnbr(nb % 10 * -1);
	}
}
