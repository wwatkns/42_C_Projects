/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:00:04 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/10 18:14:53 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	img_init(t_env *e)
{
	error((int)(e->img.adr = mlx_new_image(e->mlx, e->win.w, e->win.h)));
	e->img.img = mlx_get_data_addr(e->img.adr, &e->img.bpp, &e->img.sl,
			&e->img.endian);
	e->img.opp = e->img.bpp / 8;
}

void	img_pixel_put_hex(t_env *e, int x, int y, int hex)
{
	int pos;

	if (x >= 0 && x < e->win.w && y >= 0 && y < e->win.h)
	{
		pos = (x * e->img.opp) + (y * e->img.sl);
		e->img.img[pos] = hex % 256 / 255.0;
		e->img.img[pos + 1] = (hex >> 8) % 256 / 255.0;
		e->img.img[pos + 2] = (hex >> 16) % 256 / 255.0;
	}
}

void	img_pixel_put(t_env *e, int x, int y, t_vec3 color)
{
	int pos;

	if (x >= 0 && x < e->win.w && y >= 0 && y < e->win.h)
	{
		pos = (x * e->img.opp) + (y * e->img.sl);
		e->img.img[pos] = color.z * 255;
		e->img.img[pos + 1] = color.y * 255;
		e->img.img[pos + 2] = color.x * 255;
	}
}

t_vec3	hex_to_color(int hex)
{
	t_vec3	color;

	color.z = hex % 256 / 255.0;
	color.y = (hex >> 8) % 256 / 255.0;
	color.x = (hex >> 16) % 256 / 255.0;
	return (color);
}
