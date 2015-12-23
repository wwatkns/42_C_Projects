/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 21:28:32 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/23 19:45:27 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawline(t_env e, t_point p, t_point p1, int color)
{
	t_point d;
	t_point s;
	int		err;
	int		e2;

	d.x = ABS((p1.x - p.x));
	d.y = -ABS((p1.y - p.y));
	s.x = (p.x < p1.x ? 1 : -1);
	s.y = (p.y < p1.y ? 1 : -1);
	err = d.x + d.y;
	while (p.x != p1.x || p.y != p1.y)
	{
		mlx_pixel_put(e.mlx, e.win, p.x, p.y, color);
		e2 = 2 * err;
		if (e2 >= d.y)
		{
			err += d.y;
			p.x += s.x;
		}
		if (e2 <= d.x)
		{
			err += d.x;
			p.y += s.y;
		}
	}
}

t_point	ft_point(int x, int y)
{
	t_point p;

	p.x = x;
	p.y = y;
	return (p);
}
