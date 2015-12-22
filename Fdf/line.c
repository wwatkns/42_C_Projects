/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 21:28:32 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/22 16:56:05 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

t_line      ft_line(int x, int y, int x1, int y1)
{
	t_line line;

	line.p0.x = x;
	line.p0.y = y;
	line.p1.x = x1;
	line.p1.y = y1;
	line.dx = 0;
	line.dy = 0;
	return (line);
}
