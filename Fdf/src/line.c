/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 21:28:32 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/03 18:58:12 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawline(t_env e, t_point p, t_point p1, int color)
{
	t_point	d;
	t_point	s;
	int		err;
	int		e2;

	d.x = ABS((p1.x - p.x));
	d.y = ABS((p1.y - p.y));
	s.x = (p.x < p1.x ? 1 : -1);
	s.y = (p.y < p1.y ? 1 : -1);
	err = d.x - d.y;
	while (p.x != p1.x || p.y != p1.y)
	{
	//	ft_getalt(p, p1);
		mlx_pixel_put(e.mlx, e.win, p.x, p.y, ft_color(p, p1, color));
		e2 = 2 * err;
		if (e2 > -d.y)
		{
			err -= d.y;
			p.x += s.x;
		}
		if (e2 < d.x)
		{
			err += d.x;
			p.y += s.y;
		}
	}
}

int		ft_getalt(t_point p, t_point p1)
{
	int		x;
	int		y;
	int		dx;
	int		dy;

	x = ABS((p.x - p1.x));
	y = ABS((p.y - p1.y));
	dx = p.x - (p1.x - x) / p1.x - (p1.x - x) * 100;
	dy = p.y - (p1.y - y) / p1.y - (p1.y - y) * 100;
	return (dx);
}

int		ft_color(t_point p, t_point p1, int color)
{
	return ((color / 256) - (((float)p.x / (float)p1.x * 100.0f) +
							((float)p.y / (float)p1.x * 100.0f)) / 2);
}

t_point	ft_point(int x, int y)
{
	t_point p;

	p.x = x;
	p.y = y;
	return (p);
}
