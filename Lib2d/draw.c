/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:05:51 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/21 14:05:53 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib2d.h"

void	ft_drawline(t_env e, t_line line, int color)
{
	int sx;
	int sy;
	int err;
	int e2;

	line.dx = ABS((line.p1.x - line.p0.x));
	line.dy = -ABS((line.p1.y - line.p0.y));
	sx = (line.p0.x < line.p1.x ? 1 : -1);
	sy = (line.p0.y < line.p1.y ? 1 : -1);
	err = line.dx + line.dy;
	while (line.p0.x != line.p1.x || line.p0.y != line.p1.y)
	{
		mlx_pixel_put(e.mlx, e.win, line.p0.x, line.p0.y, color);
		e2 = 2 * err;
		if (e2 >= line.dy)
		{
			err += line.dy;
			line.p0.x += sx;
		}
		if (e2 <= line.dx)
		{
			err += line.dx;
			line.p0.y += sy;
		}
	}
}

void	ft_drawrect(t_env e, t_rect rect, int color)
{
	ft_drawline(e, ft_line(rect.p0.x, rect.p0.y, rect.p1.x, rect.p0.y), color);
	ft_drawline(e, ft_line(rect.p0.x, rect.p0.y, rect.p0.x, rect.p1.y), color);
	rect.p1.x--;
	rect.p1.y--;
	ft_drawline(e, ft_line(rect.p1.x, rect.p1.y, rect.p0.x, rect.p1.y), color);
	ft_drawline(e, ft_line(rect.p1.x, rect.p1.y, rect.p1.x, rect.p0.y), color);
}

void	ft_drawfillrect(t_env e, t_rect rect, int color)
{
	int x;

	while (rect.p0.y < rect.p1.y)
	{
		x = rect.p0.x;
		while (x < rect.p1.x)
		{
			mlx_pixel_put(e.mlx, e.win, x, rect.p0.y, color);
			x++;
		}
		rect.p0.y++;
	}
}

void    ft_drawcircle(t_env e, t_circle circle, int color)
{
	int xt;
	int yt;
	int err;

	xt = -circle.r;
	yt = 0;
	err = 2 - 2 * circle.r;
	while (xt < 0)
	{
		mlx_pixel_put(e.mlx, e.win, circle.p.x - xt, circle.p.y + yt, color);
		mlx_pixel_put(e.mlx, e.win, circle.p.x - yt, circle.p.y - xt, color);
		mlx_pixel_put(e.mlx, e.win, circle.p.x + xt, circle.p.y - yt, color);
		mlx_pixel_put(e.mlx, e.win, circle.p.x + yt, circle.p.y + xt, color);
		circle.r = err;
		err = (circle.r <= yt ? err + ++yt * 2 + 1 : err);
		err = (circle.r > xt || err > yt ? err + ++xt * 2 + 1 : err);
	}
}

void	ft_drawfillcircle(t_env e, t_circle circle, int color)
{
	int xt;
	int yt;
	int err;

	xt = -circle.r;
	yt = 0;
	err = 2 - 2 * circle.r;
	while (xt < 0)
	{
		ft_drawline(e, ft_line(circle.p.x - xt, circle.p.y - yt,
					circle.p.x + xt - 1, circle.p.y - yt), color);
		ft_drawline(e, ft_line(circle.p.x - xt, circle.p.y + yt,
					circle.p.x + xt - 1, circle.p.y + yt), color);
		circle.r = err;
		err = (circle.r <= yt ? err + ++yt * 2 + 1 : err);
		err = (circle.r > xt || err > yt ? err + ++xt * 2 + 1 : err);
	}
}
