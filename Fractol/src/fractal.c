/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:46:11 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/12 13:50:27 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_env *e, int x, int y)
{
	int		iteration;

	e->f.x = (x - e->win_w / 2) * 8.0 / e->win_w;
	e->f.y = (y - e->win_h / 2) * 8.0 / e->win_w;
	e->f.x2 = 0;
	e->f.y2 = 0;
	e->f.c_re = -0.123f;
	e->f.c_im = 0.745f;

	iteration = 0;
	while (iteration < e->f.max)
	{
		e->f.y = 2.0 * e->f.x * e->f.y + e->f.c_im;
		e->f.x = e->f.x2 - e->f.y2 + e->f.c_re;
		e->f.x2 = e->f.x * e->f.x;
		e->f.y2 = e->f.y * e->f.y;
		if (e->f.x2 + e->f.y2 >= 4)
			break ;
		iteration++;
	}
	if (iteration == e->f.max)
		ft_imgpixelput(e, x, y, 0);
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
	if (iteration == e->f.max)
		ft_imgpixelput(e, x, y, 0);
	else
		ft_imgpixelput(e, x, y, ft_getcolor(e, iteration));
}

void	ft_initfract(t_env *e)
{
	e->f.max = 100;
	e->f.dw = e->win_w / 2.0f;
	e->f.dh = e->win_h / 2.0f;
	e->f.zoom = 0.25f;
	e->f.x = 0;
	e->f.y = 0;
	e->f.offx = 0.0;
	e->f.offy = 0.0;
}