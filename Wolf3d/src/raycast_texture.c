/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 09:52:31 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/26 16:50:25 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	raycast_untextured(t_env *e, int y, int y1)
{
	short	color;

	color = 210;
	color -= e->ray.dist * 8;
	color < 0 ? color = 0 : 0;
	e->ray.side == 1 ? color /= 2 : 0;
	draw_vertical_line(e, vec2(e->ray.x, 0), y, set_rgb(125, 140, 196));
	if (e->ray.side == 0 && e->ray.dir.x > 0)
		color = 15;
	else if (e->ray.side == 0 && e->ray.dir.x < 0)
		color = 60;
	else if (e->ray.side == 1 && e->ray.dir.y > 0)
		color = 180;
	else if (e->ray.side == 1 && e->ray.dir.y < 0)
		color = 110;
	draw_vertical_line(e, vec2(e->ray.x, y), y1,
	set_rgb(color + 35, color - 15, color + 20));
	draw_vertical_line(e, vec2(e->ray.x, y1), e->win_h, set_rgb(60, 95, 182));
	e->tex.f != -1 || e->tex.c != -1 ? raycast_wall_texel(e) : 0;
	e->tex.f != -1 || e->tex.c != -1 ? floor_casting(e, y1) : 0;
}

void	raycast_textured(t_env *e, int y, int y1, int line_h)
{
	int	i;
	int	pos;

	e->tex.n = e->map.map[(int)e->ray.map.y][(int)e->ray.map.x] - 1;
	e->tex.n > e->tex.nb - 1 ? e->tex.n = 0 : 0;
	raycast_wall_texel(e);
	e->tex.texel.x = (int)(e->tex.wall * e->tex.w);
	if ((e->ray.side == 0 && e->ray.dir.x < 0) ||
		(e->ray.side == 1 && e->ray.dir.y < 0))
		e->tex.texel.x = e->tex.w - e->tex.texel.x - 1;
	i = y - 1;
	while (++i < y1)
	{
		e->tex.texel.y = (i * 2 - e->win_h + line_h) * (e->tex.h / 2) / line_h;
		pos = (e->tex.texel.x * e->tin[e->tex.n].opp) + (e->tex.texel.y *
				e->tin[e->tex.n].sl);
		e->tin[e->tex.n].rgb.r = e->ray.side ? e->tin[e->tex.n].img[pos + 2] :
							e->tin[e->tex.n].img[pos + 2] >> 1 & 0x7F;
		e->tin[e->tex.n].rgb.g = e->ray.side ? e->tin[e->tex.n].img[pos + 1] :
							e->tin[e->tex.n].img[pos + 1] >> 1 & 0x7F;
		e->tin[e->tex.n].rgb.b = e->ray.side ? e->tin[e->tex.n].img[pos] :
							e->tin[e->tex.n].img[pos] >> 1 & 0x7F;
		img_pixel_put(e, e->ray.x, i, e->tin[e->tex.n].rgb);
	}
	e->tex.f != -1 || e->tex.c != -1 ? floor_casting(e, y1) : 0;
}

void	raycast_wall_texel(t_env *e)
{
	e->ray.side == 1 ? e->tex.wall = e->ray.pos.x + ((e->ray.map.y -
	e->ray.pos.y + (1 - e->ray.step.y) / 2) / e->ray.dir.y) * e->ray.dir.x : 0;
	e->ray.side == 0 ? e->tex.wall = e->ray.pos.y + ((e->ray.map.x -
	e->ray.pos.x + (1 - e->ray.step.x) / 2) / e->ray.dir.x) * e->ray.dir.y : 0;
	e->tex.wall -= floor(e->tex.wall);
}

void	floor_casting(t_env *e, int y1)
{
	e->flr.dpos = 0;
	e->flr.dwall = e->ray.dist;
	if (e->ray.side == 0 && e->ray.dir.x > 0)
	{
		e->flr.txl_w.x = e->ray.map.x;
		e->flr.txl_w.y = e->ray.map.y + e->tex.wall;
	}
	else if (e->ray.side == 0 && e->ray.dir.x < 0)
	{
		e->flr.txl_w.x = e->ray.map.x + 1.0;
		e->flr.txl_w.y = e->ray.map.y + e->tex.wall;
	}
	else if (e->ray.side == 1 && e->ray.dir.y > 0)
	{
		e->flr.txl_w.x = e->ray.map.x + e->tex.wall;
		e->flr.txl_w.y = e->ray.map.y;
	}
	else
	{
		e->flr.txl_w.x = e->ray.map.x + e->tex.wall;
		e->flr.txl_w.y = e->ray.map.y + 1.0;
	}
	floor_casting_draw(e, y1);
}

void	floor_casting_draw(t_env *e, int y1)
{
	double	weight;
	t_rgb	rgb;

	e->i.y = y1;
	while (e->i.y++ < e->win_h)
	{
		e->flr.dist = (e->win_h) / (2.0 * e->i.y - e->win_h);
		weight = (e->flr.dist - e->flr.dpos) / (e->flr.dwall - e->flr.dpos);
		e->flr.flr.x = weight * e->flr.txl_w.x + (1.0 - weight) * e->map.pos.x;
		e->flr.flr.y = weight * e->flr.txl_w.y + (1.0 - weight) * e->map.pos.y;
		e->flr.txl_f.x = (int)(e->flr.flr.x * e->tex.w) % e->tex.w;
		e->flr.txl_f.y = (int)(e->flr.flr.y * e->tex.h) % e->tex.h;
		e->tex.f != -1 ? e->i.pos = (e->flr.txl_f.x * e->tin[e->tex.f].opp) +
		(e->flr.txl_f.y * e->tin[e->tex.f].sl) : 0;
		e->tex.f != -1 ? rgb.r = e->tin[e->tex.f].img[e->i.pos + 2] : 0;
		e->tex.f != -1 ? rgb.g = e->tin[e->tex.f].img[e->i.pos + 1] : 0;
		e->tex.f != -1 ? rgb.b = e->tin[e->tex.f].img[e->i.pos] : 0;
		e->tex.f != -1 ? img_pixel_put(e, e->ray.x, e->i.y - 1, rgb) : 0;
		e->tex.c != -1 ? e->i.pos = (e->flr.txl_f.x * e->tin[e->tex.c].opp) +
		(e->flr.txl_f.y * e->tin[e->tex.c].sl) : 0;
		e->tex.c != -1 ? rgb.r = e->tin[e->tex.c].img[e->i.pos + 2] : 0;
		e->tex.c != -1 ? rgb.g = e->tin[e->tex.c].img[e->i.pos + 1] : 0;
		e->tex.c != -1 ? rgb.b = e->tin[e->tex.c].img[e->i.pos] : 0;
		e->tex.c != -1 ? img_pixel_put(e, e->ray.x, e->win_h - e->i.y, rgb) : 0;
	}
}
