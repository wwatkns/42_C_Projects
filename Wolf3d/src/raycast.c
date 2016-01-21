/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:46:57 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/21 17:17:48 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	raycast_algo(t_env *e)
{
	while (e->ray.hit == 0)
	{
		if (e->ray.len.x < e->ray.len.y)
		{
			e->ray.len.x += e->ray.a.x;
			e->ray.map.x += e->ray.step.x;
			e->ray.side = 0;
		}
		else
		{
			e->ray.len.y += e->ray.a.y;
			e->ray.map.y += e->ray.step.y;
			e->ray.side = 1;
		}
		if (e->ray.map.x > 14 || e->ray.map.y > 14 ||
			e->ray.map.x < 0 || e->ray.map.y < 0)
			break ; // temporary, generates flickers between NE & SW walls
		if (e->map.map[e->ray.map.x][e->ray.map.y] > 0)
			e->ray.hit = 1;
	}
}

void	raycast_calc(t_env *e)
{
	if (e->ray.dir.x < 0)
	{
		e->ray.step.x = -1;
		e->ray.len.x = (e->ray.pos.x - e->ray.map.x) * e->ray.a.x;
	}
	else
	{
		e->ray.step.x = 1;
		e->ray.len.x = (e->ray.map.x + 1.0 - e->ray.pos.x) * e->ray.a.x;
	}
	if (e->ray.dir.y < 0)
	{
		e->ray.step.y = -1;
		e->ray.len.y = (e->ray.pos.y - e->ray.map.y) * e->ray.a.y;
	}
	else
	{
		e->ray.step.y = 1;
		e->ray.len.y = (e->ray.map.y + 1.0 - e->ray.pos.y) * e->ray.a.y;
	}
}

void	raycast_draw(t_env *e, int x)
{
	int		y;
	int		y1;
	int		line_height;
	short	color;

	if (e->ray.side == 0)
		e->ray.dist = fabs(((float)e->ray.map.x - e->ray.pos.x +
		(1 - e->ray.step.x) / 2) / e->ray.dir.x);
	else
		e->ray.dist = fabs(((float)e->ray.map.y - e->ray.pos.y +
		(1 - e->ray.step.y) / 2) / e->ray.dir.y);
	line_height = abs((int)(e->win_h / e->ray.dist));
	y = -line_height / 2 + e->win_h / 2;
	y1 = line_height / 2 + e->win_h / 2;
	y < 0 ? y = 0 : 0;
	y1 >= e->win_h ? y1 = e->win_h - 1 : 0;
	color = (e->ray.side == 1 ? 128 : 255);
	draw_vertical_line(e, vec2(x, y), y1, set_rgb(color, color, color));
}

void	raycast_init(t_env *e, int x)
{
	float	cam;
	float	dir_x2;
	float	dir_y2;

	cam = 2 * x / (float)e->win_w - 1;
	dir_x2 = e->cam.dir.x * 2;
	dir_y2 = e->cam.dir.y * 2;
	e->ray.hit = 0;
	e->ray.pos.x = e->map.pos.x;
	e->ray.pos.y = e->map.pos.y;
	e->ray.map.x = (int)e->map.pos.x;
	e->ray.map.y = (int)e->map.pos.y;
	e->ray.dir.x = e->cam.dir.x + e->cam.pln.x * cam;
	e->ray.dir.y = e->cam.dir.y + e->cam.pln.y * cam;
	e->ray.a.x = sqrt(1.0 + dir_y2 / dir_x2);
	e->ray.a.y = sqrt(1.0 + dir_x2 / dir_y2);
}

void	raycast(t_env *e)
{
	int		x;

	x = 0;
	while (x < e->win_w)
	{
		raycast_init(e, x);
		raycast_calc(e);
		raycast_algo(e);
		raycast_draw(e, x);
		x++;
	}
}
