/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:59:50 by elchouai          #+#    #+#             */
/*   Updated: 2019/02/28 18:15:26 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_julia(int x, int y, t_fractol *data)
{
	if (data->fract == 1 && data->julia_mouse == 1)
	{
		data->comlpex_re = x * 3;
		data->comlpex_im = y * 3 - 800;
		fract_calc(data);
	}
	return (0);
}

void	julia_init(t_fractol *data)
{
	data->it_max = 50;
	data->zoom = 200;
	data->x1 = -2.0;
	data->y1 = -1.9;
	data->color = 265;
	data->comlpex_re = 0.285;
	data->comlpex_im = 0.01;
	data->julia_mouse = 1;
}

void	julia_calc(t_fractol *data)
{
	data->z_re = data->x / data->zoom + data->x1;
	data->z_im = data->y / data->zoom + data->y1;
	data->it = 0;
	while (data->z_re * data->z_re + data->z_im
			* data->z_im < 4 && data->it < data->it_max)
	{
		data->tmp = data->z_re;
		data->z_re = data->z_re * data->z_re -
			data->z_im * data->z_im - 0.8 + (data->comlpex_re / WIDTH);
		data->z_im = 2 * data->z_im * data->tmp + data->comlpex_im / WIDTH;
		data->it++;
	}
	if (data->it == data->it_max)
		put_pxl_to_img(data, data->x, data->y, 0x000000);
	else
		put_pxl_to_img(data, data->x, data->y, (data->color * data->it));
}

void	*julia(void *tab)
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
			julia_calc(data);
			data->y++;
		}
		data->x++;
	}
	return (tab);
}

void	julia_pthread(t_fractol *data)
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
		pthread_create(&t[i], NULL, julia, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
