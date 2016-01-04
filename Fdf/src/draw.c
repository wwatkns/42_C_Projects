/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 11:56:57 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/04 18:28:45 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawline(t_env e, t_point p, t_point p1)
{
	t_point	d;
	t_point	s;
	int		err;
	int		e2;

	d.x = ABS((p1.x - p.x));
	d.y = ABS((p1.y - p.y));
	s.x = (p.x < p1.x ? 1 : -1);
	s.y = (p.y < p1.y ? 1 : -1);
	err = d.x - d.y;
	while (p.x != p1.x || p.y != p1.y)
	{
		ft_imgpixelput(&e, p.x, p.y, ft_getcolor(e, p, p1));
		e2 = 2 * err;
		if (e2 > -d.y)
		{
			err -= d.y;
			p.x += s.x;
		}
		if (e2 < d.x)
		{
			err += d.x;
			p.y += s.y;
		}
	}
}

void	ft_imgpixelput(t_env *e, int x, int y, int color)
{
	int	pos;

	if (x >= 0 && x < e->scw && y >= 0 && y < e->sch)
	{
		pos = (x * e->img.bpp / 8) + (y * e->img.sl);
		e->img.img[pos] = color % 256;
		e->img.img[pos + 1] = (color >> 8) % 256;
		e->img.img[pos + 2] = (color >> 16) % 256;
	}
}

int		ft_getcolor(t_env e, t_point p, t_point p1)
{
	int q1;
	int	q2;
	int q3;
	int q4;

	q1 = e.minh + e.palette.step;
	q2 = q1 + e.palette.step;
	q3 = q2 + e.palette.step;
	q4 = q3 + e.palette.step;
	if ((p.h + p1.h) / 2 >= q4)
		return (e.palette.c5);
	if ((p.h + p1.h) / 2 >= q3)
		return (e.palette.c4);
	if ((p.h + p1.h) / 2 >= q2)
		return (e.palette.c3);
	if ((p.h + p1.h) / 2 >= q1)
		return (e.palette.c2);
	return (e.palette.c1);
}

void	ft_setpalette(t_env *e, int palette)
{
	e->key.p = 0;
	e->palette.i = e->palette.i < 4 ? e->palette.i + 1 : 0;
	e->palette.step = (float)ABS((e->minh - e->maxh)) / 4.5f;
	if (palette == 0)
	{
		e->palette.c1 = 0x40833E;
		e->palette.c2 = 0x4E945D;
		e->palette.c3 = 0xA58277;
		e->palette.c4 = 0xA7B5D2;
		e->palette.c5 = 0xD1E7F0;
	}
	else if (palette == 1)
	{
		e->palette.c1 = 0xD3BDA4;
		e->palette.c2 = 0xD1605C;
		e->palette.c3 = 0x8B633D;
		e->palette.c4 = 0xE9A663;
		e->palette.c5 = 0xFFDF85;
	}
	else if (palette == 2)
	{
		e->palette.c1 = 0x718A8D;
		e->palette.c2 = 0x875C5C;
		e->palette.c3 = 0x585858;
		e->palette.c4 = 0x92BD6B;
		e->palette.c5 = 0x7AB288;
	}
	else if (palette == 3)
	{
		e->palette.c1 = 0x28A0D4;
		e->palette.c2 = 0x4DB5CB;
		e->palette.c3 = 0x71BDB7;
		e->palette.c4 = 0x6FE2BF;
		e->palette.c5 = 0xB4D9B5;
	}
	else if (palette == 4)
	{
		e->palette.c1 = 0xA6E5CA;
		e->palette.c2 = 0xDAEBBE;
		e->palette.c3 = 0xFED3B3;
		e->palette.c4 = 0xFEABA5;
		e->palette.c5 = 0xFE8992;
	}
}
