/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 09:52:31 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/23 12:19:20 by wwatkins         ###   ########.fr       */
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
	draw_vertical_line(e, vec2(e->ray.x, y), y1,
	set_rgb(color + 45, color + 25, color));
	draw_vertical_line(e, vec2(e->ray.x, y1), e->win_h, set_rgb(60, 95, 182));
}

void	raycast_textured(t_env *e, int y, int y1, int line_h)
{
	int		i;
	int		num;
	int		color;
	double	wall;

	num = e->map.map[(int)e->ray.map.y][(int)e->ray.map.x] - 1;
	e->ray.side == 1 ? wall = e->ray.pos.x + ((e->ray.map.y - e->ray.pos.y +
	(1 - e->ray.step.y) / 2) / e->ray.dir.y) * e->ray.dir.x : 0;
	e->ray.side == 0 ? wall = e->ray.pos.y + ((e->ray.map.x - e->ray.pos.x +
	(1 - e->ray.step.x) / 2) / e->ray.dir.x) * e->ray.dir.y : 0;
	wall -= floor(wall);
	e->tex.texel.x = (int)(wall * e->tex.w);
	if ((e->ray.side == 0 && e->ray.dir.x < 0) ||
		(e->ray.side == 1 && e->ray.dir.y < 0))
		e->tex.texel.x = e->tex.w - e->tex.texel.x - 1;
	i = y - 1;
	while (++i < y1)
	{
		e->tex.texel.y = (i * 2 - e->win_h + line_h) * (e->tex.h / 2) / line_h;
		color = e->tex.texture[num][e->tex.h * e->tex.texel.y + e->tex.texel.x];
		e->ray.side ? color = (color >> 1) & 0x7F7F7F : 0;
		img_pixel_put_hex(e, e->ray.x, i, color);
	}
}
