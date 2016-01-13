/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:46:11 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/13 14:26:08 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_env *e, int x, int y)
{
	int		iteration;

	e->f.x = (x - e->hwin_w) / e->f.zwin_w + e->f.offx;
	e->f.y = (y - e->hwin_h) / e->f.zwin_h + e->f.offy;
	e->f.x2 = e->f.x * e->f.x;
	e->f.y2 = e->f.y * e->f.y;
	iteration = 0;
	while (e->f.x2 + e->f.y2 < 4 && iteration < e->f.max)
	{
		e->f.y = 2.0 * e->f.x * e->f.y + e->f.c_im;
		e->f.x = e->f.x2 - e->f.y2 + e->f.c_re;
		e->f.x2 = e->f.x * e->f.x;
		e->f.y2 = e->f.y * e->f.y;
		++iteration;
	}
	if (e->key.o)
		iteration == e->f.max ? ft_imgpixelput(e, x, y, ft_getcolor(e, -1)) :
		ft_imgpixelput(e, x, y, ft_getcolor(e, iteration));
	else
		ft_imgpixelput(e, x, y, ft_getcolor(e, iteration));
}

void	ft_mandelbrot(t_env *e, int x, int y)
{
	int		iteration;

	e->f.x = 0;
	e->f.y = 0;
	e->f.x2 = 0;
	e->f.y2 = 0;
	e->f.c_re = (x - e->hwin_w) / e->f.zwin_w + e->f.offx;
	e->f.c_im = (y - e->hwin_h) / e->f.zwin_h + e->f.offy;
	iteration = 0;
	while (e->f.x2 + e->f.y2 < 4 && iteration < e->f.max)
	{
		e->f.y = 2.0 * e->f.x * e->f.y + e->f.c_im;
		e->f.x = e->f.x2 - e->f.y2 + e->f.c_re;
		e->f.x2 = e->f.x * e->f.x;
		e->f.y2 = e->f.y * e->f.y;
		++iteration;
	}
	if (e->key.o)
		iteration == e->f.max ? ft_imgpixelput(e, x, y, ft_getcolor(e, -1)) :
		ft_imgpixelput(e, x, y, ft_getcolor(e, iteration));
	else
		ft_imgpixelput(e, x, y, ft_getcolor(e, iteration));
}

void	ft_burningship(t_env *e, int x, int y)
{
	int		iteration;

	e->f.x = 0;
	e->f.y = 0;
	e->f.x2 = 0;
	e->f.y2 = 0;
	e->f.c_re = (x - e->hwin_w) / e->f.zwin_w + e->f.offx;
	e->f.c_im = (y - e->hwin_h) / e->f.zwin_h + e->f.offy;
	iteration = 0;
	while (e->f.x2 + e->f.y2 < 4 && iteration < e->f.max)
	{
		e->f.y = 2.0 * ABS((e->f.x * e->f.y)) + e->f.c_im;
		e->f.x = e->f.x2 - e->f.y2 - e->f.c_re;
		e->f.x2 = e->f.x * e->f.x;
		e->f.y2 = e->f.y * e->f.y;
		++iteration;
	}
	if (e->key.o)
		iteration == e->f.max ? ft_imgpixelput(e, x, y, ft_getcolor(e, -1)) :
		ft_imgpixelput(e, x, y, ft_getcolor(e, iteration));
	else
		ft_imgpixelput(e, x, y, ft_getcolor(e, iteration));
}

void	ft_tricorn(t_env *e, int x, int y)
{
	int		iteration;

	e->f.x = 0;
	e->f.y = 0;
	e->f.x2 = 0;
	e->f.y2 = 0;
	e->f.c_re = (x - e->hwin_w) / e->f.zwin_w + e->f.offx;
	e->f.c_im = (y - e->hwin_h) / e->f.zwin_h + e->f.offy;
	iteration = 0;
	while (e->f.x2 + e->f.y2 < 4 && iteration < e->f.max)
	{
		e->f.y = -2.0 * e->f.x * e->f.y + e->f.c_im;
		e->f.x = e->f.x2 - e->f.y2 + e->f.c_re;
		e->f.x2 = e->f.x * e->f.x;
		e->f.y2 = e->f.y * e->f.y;
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
	e->f.max = 100;
	e->f.zoom = 0.25f;
	e->f.x = 0;
	e->f.y = 0;
	e->f.offx = 0.0;
	e->f.offy = 0.0;
	e->f.c_re = 0.0;
	e->f.c_im = 0.0;
	e->f.color = 0;
}
