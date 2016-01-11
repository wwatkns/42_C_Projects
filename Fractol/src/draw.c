/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:19:51 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/11 15:15:11 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_imgpixelput(t_env *e, int x, int y, int color)
{
	int pos;

	if (x >= 0 && x < e->win_w && y >= 0 && y < e->win_h)
	{
		pos = (x * e->img.bpp / 8) + (y * e->img.sl);
		e->img.img[pos] = color % 256;
		e->img.img[pos + 1] = (color >> 8) % 256;
		e->img.img[pos + 2] = (color >> 16) % 256;
	}
}

void	ft_initimg(t_env *e)
{
	ft_error(((int)(e->img.adr = mlx_new_image(e->mlx, e->win_w, e->win_h))));
	e->img.img = mlx_get_data_addr(e->img.adr, &e->img.bpp,
	&e->img.sl, &e->img.endian);
}

int		ft_getcolor(t_env *e, int iteration)
{
	int color;

	if (e->win_w == 0)
		exit(0);
	color = iteration * 0x000FF0;
	return (color);
}
