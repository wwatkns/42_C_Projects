/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:46:11 by wwatkins          #+#    #+#             */
/*   Updated: 2017/04/15 21:52:44 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_env *e, int x, int y)
{
	int		iteration;
	t_fract	f;

	f.x = (x - e->hwin_w) / e->f.zwin_w + e->f.offx;
	f.y = (y - e->hwin_h) / e->f.zwin_h + e->f.offy;
	f.x2 = f.x * f.x;
	f.y2 = f.y * f.y;
	iteration = 0;
	while (f.x2 + f.y2 < 4 && iteration < e->f.max)
	{
		f.y = (f.x + f.x) * f.y + e->f.c_im;
		f.x = f.x2 - f.y2 + e->f.c_re;
		f.x2 = f.x * f.x;
		f.y2 = f.y * f.y;
		++iteration;
	}

	if (e->key.o)
		iteration == e->f.max ? ft_imgpixelput(e, x, y, ft_getcolor(e, -1)) :
		ft_imgpixelput(e, x, y, smooth_shading(&f, &iteration, 3));
	else
		iteration == e->f.max ? ft_imgpixelput(e, x, y, ft_getcolor(e, -1)) :
		ft_imgpixelput(e, x, y, ft_getcolor(e, iteration));
}

void	ft_mandelbrot(t_env *e, int x, int y)
{
	int		iteration;
	t_fract	f;

	f.n = e->f.n;
	f.x = 0;
	f.y = 0;
	f.x2 = 0;
	f.y2 = 0;
	f.c_re = (x - e->hwin_w) / e->f.zwin_w + e->f.offx;
	f.c_im = (y - e->hwin_h) / e->f.zwin_h + e->f.offy;
	iteration = 0;
	while (f.x2 + f.y2 < 4 && iteration < e->f.max)
	{
		f.y = (f.x + f.x) * f.y + f.c_im;
		f.x = f.x2 - f.y2 + f.c_re;
		f.x2 = f.x * f.x;
		f.y2 = f.y * f.y;
		++iteration;
	}
	if (e->key.o)
		iteration == e->f.max ? ft_imgpixelput(e, x, y, ft_getcolor(e, -1)) :
		ft_imgpixelput(e, x, y, smooth_shading(&f, &iteration, 3));
	else
		iteration == e->f.max ? ft_imgpixelput(e, x, y, ft_getcolor(e, -1)) :
		ft_imgpixelput(e, x, y, ft_getcolor(e, iteration));
}

void	ft_burningship(t_env *e, int x, int y)
{
	int		iteration;
	t_fract	f;

	f.n = e->f.n;
	f.x = 0;
	f.y = 0;
	f.x2 = 0;
	f.y2 = 0;
	f.c_re = (x - e->hwin_w) / e->f.zwin_w + e->f.offx;
	f.c_im = (y - e->hwin_h) / e->f.zwin_h + e->f.offy;
	iteration = 0;
	while (f.x2 + f.y2 < 4 && iteration < e->f.max)
	{
		f.y = 2.0 * ABS((f.x * f.y)) + f.c_im;
		f.x = f.x2 - f.y2 - f.c_re;
		f.x2 = f.x * f.x;
		f.y2 = f.y * f.y;
		++iteration;
	}
	if (e->key.o)
		iteration == e->f.max ? ft_imgpixelput(e, x, y, ft_getcolor(e, -1)) :
		ft_imgpixelput(e, x, y, smooth_shading(&f, &iteration, 3));
	else
		iteration == e->f.max ? ft_imgpixelput(e, x, y, ft_getcolor(e, -1)) :
		ft_imgpixelput(e, x, y, ft_getcolor(e, iteration));
}

void	ft_tricorn(t_env *e, int x, int y)
{
	int		iteration;
	t_fract	f;

	f.x = 0;
	f.y = 0;
	f.x2 = 0;
	f.y2 = 0;
	f.c_re = (x - e->hwin_w) / e->f.zwin_w + e->f.offx;
	f.c_im = (y - e->hwin_h) / e->f.zwin_h + e->f.offy;
	iteration = 0;
	while (f.x2 + f.y2 < 4 && iteration < e->f.max)
	{
		f.y = -(f.x + f.x) * f.y + f.c_im;
		f.x = f.x2 - f.y2 + f.c_re;
		f.x2 = f.x * f.x;
		f.y2 = f.y * f.y;
		++iteration;
	}
	if (e->key.o)
		iteration == e->f.max ? ft_imgpixelput(e, x, y, ft_getcolor(e, -1)) :
		ft_imgpixelput(e, x, y, ft_getcolor(e, iteration));
	else
		ft_imgpixelput(e, x, y, ft_getcolor(e, iteration));
}

void	ft_initfract(t_env *e)
{
	e->f.max = 70;
	e->f.zoom = 0.25f;
	e->f.x = 0;
	e->f.y = 0;
	e->f.offx = 0.0;
	e->f.offy = 0.0;
	e->f.c_re = 0.0;
	e->f.c_im = 0.0;
	e->f.color = 0;
}
