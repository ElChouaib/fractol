/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:03:42 by elchouai          #+#    #+#             */
/*   Updated: 2019/03/29 16:03:47 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	tricorl_init(t_fractol *data)
{
	data->it_max = 35;
	data->zoom = 265;
	data->x1 = -2.35;
	data->y1 = -1.3;
	data->color = 265;
}

void	tricorl_calc(t_fractol *data)
{
	data->comlpex_re = data->x / data->zoom + data->x1;
	data->comlpex_im = data->y / data->zoom + data->y1;
	data->z_re = 0;
	data->z_im = 0;
	data->it = 0;
	while (data->z_re * data->z_re + data->z_im *
			data->z_im < 4 && data->it < data->it_max)
	{
		data->tmp = data->z_re;
		data->z_re = data->z_re * data->z_re -
			data->z_im * data->z_im + data->comlpex_re;
		data->z_im = -2 * data->z_im * data->tmp + data->comlpex_im;
		data->it++;
	}
	if (data->it == data->it_max)
		put_pxl_to_img(data, data->x, data->y, 0x000000);
	else
		put_pxl_to_img(data, data->x, data->y, (data->color * data->it));
}

void	*tricorl(void *tab)
{
	t_fractol	*data;
	int			tmp;

	data = (t_fractol *)tab;
	data->x = 0;
	tmp = data->y;
	while (data->x < WIDTH)
	{
		data->y = tmp;
		while (data->y < data->y_max)
		{
			tricorl_calc(data);
			data->y++;
		}
		data->x++;
	}
	return (tab);
}

void	tricorl_pthread(t_fractol *data)
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
		pthread_create(&t[i], NULL, tricorl, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
