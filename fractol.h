/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:58:02 by elchouai          #+#    #+#             */
/*   Updated: 2019/03/29 16:45:12 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "libft/libft.h"
# include "mlx.h"
# include "math.h"
# include "pthread.h"
# define WIDTH 750
# define THREAD_WIDTH 5
# define THREAD_NUMBER 150

typedef struct	s_fractol
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*img_ptr;
	int				endian;
	int				sl;
	int				bpp;
	int				fract;
	int				color;
	int				julia_mouse;
	int				x;
	int				y;
	int				y_max;
	int				it;
	int				it_max;
	int				show_text;
	long double		zoom;
	long double		x1;
	long double		y1;
	long double		comlpex_re;
	long double		comlpex_im;
	long double		z_re;
	long double		z_im;
	long double		tmp;
}				t_fractol;

int				key_hook(int keycode, t_fractol *data);
int				key_hook2(int keycode, t_fractol *data);
void			ft_zoom(int x, int y, t_fractol *data);
void			ft_dezoom(int x, int y, t_fractol *data);
int				mouse_hook(int mousecode, int x, int y, t_fractol *data);

void			mandelbrot_init(t_fractol *data);
void			mandelbrot_calc(t_fractol *data);
void			*mandelbrot(void *tab);
void			mandelbrot_pthread(t_fractol *data);

int				mouse_julia(int x, int y, t_fractol *data);
void			julia_init(t_fractol *data);
void			julia_calc(t_fractol *data);
void			*julia(void *tab);
void			julia_pthread(t_fractol *data);

void			burningships_init(t_fractol *data);
void			burningships_calc(t_fractol *data);
void			*burningships(void *tab);
void			burningships_pthread(t_fractol *data);

void			tricorl_pthread(t_fractol *data);
void			tricorl_calc(t_fractol *data);
void			*tricorl(void *tab);
void			tricorl_init(t_fractol *data);

int				ft_close(void);
void			put_pxl_to_img(t_fractol *data, int x, int y, int color);
void			put_text(t_fractol *data);

void			fract_calc(t_fractol *data);
void			fract_init(t_fractol *data);
void			mlx_win_init(t_fractol *data);
int				fract_comp(char **av, t_fractol *data);
#endif
