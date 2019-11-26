/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:58:56 by elchouai          #+#    #+#             */
/*   Updated: 2018/10/15 15:00:32 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb >= 0 && nb < 10)
	{
		ft_putchar_fd(nb + '0', fd);
	}
	else if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else if (nb > -10)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd(-1 * nb + '0', fd);
	}
	else
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-1 * (nb / 10), fd);
		ft_putnbr_fd(nb % 10 * -1, fd);
	}
}
