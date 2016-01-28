/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:00:04 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/28 13:08:58 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	img_init(t_env *e)
{
	error((int)(e->img.adr = mlx_new_image(e->mlx, e->win_w, e->win_h)));
	e->img.img = mlx_get_data_addr(e->img.adr, &e->img.bpp, &e->img.sl,
			&e->img.endian);
	e->img.opp = e->img.bpp / 8;
}

void	img_pixel_put(t_env *e, int x, int y, t_rgb rgb)
{
	int pos;

	if (x >= 0 && x < e->win_w && y >= 0 && y < e->win_h)
	{
		pos = (x * e->img.opp) + (y * e->img.sl);
		e->img.img[pos] = rgb.b;
		e->img.img[pos + 1] = rgb.g;
		e->img.img[pos + 2] = rgb.r;
	}
}

t_rgb	set_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	t_rgb	rgb;

	rgb = (t_rgb) { r, g, b };
	return (rgb);
}
