/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:19:51 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/13 14:45:10 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_imgpixelput(t_env *e, int x, int y, int *rgb)
{
	int pos;

	if (x >= 0 && x < e->win_w && y >= 0 && y < e->win_h)
	{
		pos = (x * e->img.opp) + (y * e->img.sl);
		e->img.img[pos] = rgb[2];
		e->img.img[pos + 1] = rgb[1];
		e->img.img[pos + 2] = rgb[0];
	}
	ft_memdel((void**)&rgb);
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
	int *rgb;

	rgb = (int*)malloc(sizeof(int) * 3);
	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b;
	return (rgb);
}

int		*ft_getcolor(t_env *e, int i)
{
	if (i == -1)
		return (ft_setrgb(0, 0, 0));
	if (e->f.color == 0)
		return (ft_setrgb(i * 80 / e->f.max, i * 200 / e->f.max, 50));
	if (e->f.color == 1)
	{
		return (ft_setrgb(i * 100 / e->f.max + 155, i * 220 / e->f.max + 20,
		i * 160 / e->f.max + 10));
	}
	if (e->f.color == 2)
		return (ft_setrgb(200 - i * i / 2, 155 - i * 125 / e->f.max, i * 9));
	if (e->f.color == 3)
		return (ft_setrgb(50, i * 200 / e->f.max + 55, 75));
	if (e->f.color == 4)
	{
		return (ft_setrgb(i * 240 / e->f.max + 50, i * 130 / e->f.max + 50,
		i * 80 / e->f.max + 75));
	}
	if (e->f.color == 5)
		return (ft_setrgb(i * 2, i * 5, i * 7 + 50));
	if (e->f.color == 6)
		return (ft_setrgb(i * i, i * 100 / e->f.max + 55, 75));
	return (ft_setrgb(i * 240 / e->f.max + 15, i * 240 / e->f.max,
	i * 240 / e->f.max + 15));
}
