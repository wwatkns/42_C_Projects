/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:48:31 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/18 11:52:55 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_imgpixelput(t_env *e, int x, int y, int *rgb)
{
	int pos;

	if (x >= 0 && x < e->win_w && y >= 0 && y < e->win_h)
	{
		pos = (x * e->img.opp) + (y * e->img.sl);
		e->img.img[pos] = rgb[0];
		e->img.img[pos + 1] = rgb[1];
		e->img.img[pos + 2] = rgb[2];
	}
}

void	ft_initimg(t_env *e)
{
	ft_error(((int)(e->img.adr = mlx_new_image(e->mlx, e->win_w, e->win_h))));
	e->img.img = mlx_get_data_addr(e->img.adr, &e->img.bpp,
	&e->img.sl, &e->img.endian);
	e->img.opp = e->img.bpp / 8;
}

int		*ft_setrgb(int r, int g, int b)
{
	static int	rgb[3];

	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b;
	return (rgb);
}
