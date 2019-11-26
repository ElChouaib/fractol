/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningships.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:45:41 by elchouai          #+#    #+#             */
/*   Updated: 2019/03/29 16:47:34 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burningships_init(t_fractol *data)
{
	data->it_max = 50;
	data->zoom = 220;
	data->x1 = -2.2;
	data->y1 = -2.5;
	data->color = 265;
}

void	burningships_calc(t_fractol *data)
{
	data->comlpex_re = data->x / data->zoom + data->x1;
	data->comlpex_im = data->y / data->zoom + data->y1;
	data->z_re = 0;
	data->z_im = 0;
	data->it = 0;
	while (data->z_re * data->z_re + data->z_im * data->z_im < 4
			&& data->it < data->it_max)
	{
		data->tmp = data->z_re * data->z_re -
		data->z_im * data->z_im + data->comlpex_re;
		data->z_im = fabsl(2 * data->z_re * data->z_im) + data->comlpex_im;
		data->z_re = data->tmp;
		data->it++;
	}
	if (data->it == data->it_max)
		put_pxl_to_img(data, data->x, data->y, 0x000000);
	else
		put_pxl_to_img(data, data->x, data->y, (data->color * data->it));
}

void	*burningships(void *tab)
{
	int			tmp;
	t_fractol	*data;

	data = (t_fractol *)tab;
	data->x = 0;
	tmp = data->y;
	while (data->x < WIDTH)
	{
		data->y = tmp;
		while (data->y < data->y_max)
		{
			burningships_calc(data);
			data->y++;
		}
		data->x++;
	}
	return (tab);
}

void	burningships_pthread(t_fractol *data)
{
	t_fractol	tab[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = 0;
	while (i < THREAD_NUMBER)
	{
		ft_memcpy((void*)&tab[i], (void*)data, sizeof(t_fractol));
		tab[i].y = THREAD_WIDTH * i;
		tab[i].y_max = THREAD_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, burningships, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
