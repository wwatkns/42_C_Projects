/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:46:57 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/26 14:39:22 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	raycast(t_env *e)
{
	e->ray.x = 0;
	while (e->ray.x < e->win_w)
	{
		raycast_init(e);
		raycast_calc(e);
		raycast_algo(e);
		raycast_draw(e);
		e->ray.x++;
	}
}

void	raycast_init(t_env *e)
{
	float	cam;
	t_vec2	dir_pow;

	cam = (2 * e->ray.x / (float)e->win_w) - 1;
	e->ray.hit = 0;
	e->ray.pos = e->map.pos;
	e->ray.dir.x = e->cam.dir.x + e->cam.pln.x * cam;
	e->ray.dir.y = e->cam.dir.y + e->cam.pln.y * cam;
	e->ray.map = vec2i(e->ray.pos);
	dir_pow = vec2_mul(e->ray.dir, e->ray.dir);
	e->ray.a.x = sqrt(1 + dir_pow.y / dir_pow.x);
	e->ray.a.y = sqrt(1 + dir_pow.x / dir_pow.y);
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
		e->map.map[e->ray.map.y][e->ray.map.x] > 0 ? e->ray.hit = 1 : 0;
	}
}

void	raycast_draw(t_env *e)
{
	int		y;
	int		y1;
	int		line_h;

	if (e->ray.side == 0)
		e->ray.dist = ABS(((e->ray.map.x -
		e->ray.pos.x + (1 - e->ray.step.x) / 2) / e->ray.dir.x));
	else
		e->ray.dist = ABS(((e->ray.map.y -
		e->ray.pos.y + (1 - e->ray.step.y) / 2) / e->ray.dir.y));
	line_h = ABS((int)(e->win_h / e->ray.dist));
	y = (int)(-line_h / 2 + e->hwin_h);
	y1 = (int)(line_h / 2 + e->hwin_h);
	y < 0 ? y = 0 : 0;
	y1 >= e->win_h ? y1 = e->win_h : 0;
	if (e->arg.texture)
		raycast_textured(e, y, y1, line_h);
	else
		raycast_untextured(e, y, y1);
}
