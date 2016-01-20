/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:48:31 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/20 11:52:05 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_line(t_env *e, t_vec2i p, t_vec2i p1)
{
	t_vec2i	d;
	t_vec2i	s;
	int		err;
	int		e2;

	d.x = ABS((p1.x - p.x));
	d.y = ABS((p1.y - p.y));
	s.x = (p.x < p1.x ? 1 : -1);
	s.y = (p.y < p1.y ? 1 : -1);
	err = d.x - d.y;
	while (p.x != p1.x || p.y != p1.y)
	{
		img_pixel_put(e, p.x, p.y, set_rgb(255, 255, 255));
		e2 = err + err;
		e2 > -d.y ? err -= d.y : 0;
		e2 > -d.y ? p.x += s.x : 0;
		e2 < d.x ? err += d.x : 0;
		e2 < d.x ? p.y += s.y : 0;
	}
}

void	img_pixel_put(t_env *e, int x, int y, int *rgb)
{
	int pos;

	if (x >= 0 && x < e->win_w && y >= 0 && y < e->win_h)
	{
		pos = (x * e->img.opp) + (y * e->img.sl);
		e->img.img[pos] = rgb[2];
		e->img.img[pos + 1] = rgb[1];
		e->img.img[pos + 2] = rgb[0];
	}
}

void	img_init(t_env *e)
{
	error(((int)(e->img.adr = mlx_new_image(e->mlx, e->win_w, e->win_h))));
	e->img.img = mlx_get_data_addr(e->img.adr, &e->img.bpp,
			&e->img.sl, &e->img.endian);
	e->img.opp = e->img.bpp / 8;
}

int		*set_rgb(int r, int g, int b)
{
	static int	rgb[3];

	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b;
	return (rgb);
}
