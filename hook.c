/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 17:01:48 by elchouai          #+#    #+#             */
/*   Updated: 2019/04/20 19:58:10 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_define.h"

int		key_hook2(int keycode, t_fractol *data)
{
	if (keycode == KEY_V)
		data->color += 4050;
	else if (keycode == KEY_C)
		data->color += 265;
	else if (keycode == KEY_S)
		data->julia_mouse = !data->julia_mouse;
	else if (keycode == KEY_T)
		data->show_text = !data->show_text;
	return (0);
}

int		key_hook(int keycode, t_fractol *data)
{
	if (keycode == KEY_ECHAP)
		exit(1);
	else if (keycode == KEY_SUP)
		data->it_max += 50;
	else if (keycode == KEY_INF)
		data->it_max -= 50;
	else if (keycode == KEY_RIGHT)
		data->x1 -= 30 / data->zoom;
	else if (keycode == KEY_LEFT)
		data->x1 += 30 / data->zoom;
	else if (keycode == KEY_UP)
		data->y1 += 30 / data->zoom;
	else if (keycode == KEY_DOWN)
		data->y1 -= 30 / data->zoom;
	else if (keycode == KEY_SPACE)
		fract_init(data);
	else if (keycode == KEY_B)
		data->color += 1677216;
	key_hook2(keycode, data);
	fract_calc(data);
	return (0);
}

void	ft_zoom(int x, int y, t_fractol *data)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom * 1.1));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom * 1.1));
	data->zoom *= 1.1;
	data->it_max++;
}

void	ft_dezoom(int x, int y, t_fractol *data)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom / 1.1));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom / 1.1));
	data->zoom /= 1.1;
	data->it_max--;
}

int		mouse_hook(int mousecode, int x, int y, t_fractol *data)
{
	if (mousecode == MOUSE_BEHIND)
		ft_zoom(x, y, data);
	else if (mousecode == MOUSE_FORWARD)
		ft_dezoom(x, y, data);
	fract_calc(data);
	return (0);
}
