/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 11:56:57 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/05 13:39:07 by wwatkins         ###   ########.fr       */
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
	e->palette.i = e->palette.i < 5 ? e->palette.i + 1 : 0;
	e->palette.step = (float)ABS((e->minh - e->maxh)) / 4.5f;
	if (palette == 0)
	{
		e->palette.c1 = 0x26532B;
		e->palette.c2 = 0x5A8D48;
		e->palette.c3 = 0x7C5A4D;
		e->palette.c4 = 0x94999F;
		e->palette.c5 = 0xFFF9F5;
	}
	else if (palette == 1)
	{
		e->palette.c1 = 0x31231E;
		e->palette.c2 = 0x5A3A31;
		e->palette.c3 = 0x84714F;
		e->palette.c4 = 0xE3D888;
		e->palette.c5 = 0xE2F1AF;
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
		e->palette.c1 = 0x293132;
		e->palette.c2 = 0x474044;
		e->palette.c3 = 0x4F5165;
		e->palette.c4 = 0x547AA5;
		e->palette.c5 = 0x50D8D7;
	}
	else if (palette == 4)
	{
		e->palette.c1 = 0xFFBD00;
		e->palette.c2 = 0xFF5400;
		e->palette.c3 = 0xFF0054;
		e->palette.c4 = 0x9E0059;
		e->palette.c5 = 0x390099;
	}
}
