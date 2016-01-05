/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 11:56:57 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/05 17:27:36 by wwatkins         ###   ########.fr       */
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
	int	i;
	int	*q;

	i = 2;
	q = (int*)malloc(sizeof(int) * e.palette.cn + 1);
	q[0] = 0;
	q[1] = e.minh + e.palette.step;
	while (i <= e.palette.cn)
	{
		q[i] = q[i - 1] + e.palette.step;
		i++;
	}
	i = e.palette.cn;
	while (i > 0)
	{
		if ((p.h + p1.h) / 2 >= q[i])
			return (e.palette.c[i]);
		i--;
	}
	return (e.palette.c[0]);
}

void	ft_setpalette(t_env *e)
{
	int		i;
	int		fd;
	char	*line;

	e->key.p = 0;
	i = 0;
	fd = open(e->av, O_RDONLY);
	get_next_line(fd, &line);
	e->palette.pn = ft_atoi(line) - 1;
	get_next_line(fd, &line);
	e->palette.cn = ft_atoi(line) - 1;
	e->palette.c = (int*)malloc(sizeof(int) * e->palette.cn + 1);
	e->palette.step = (e->maxh - e->minh) / (e->palette.cn);
	printf("step: %f, cn: %d\n", e->palette.step, e->palette.cn);
	while (i < e->palette.i * (e->palette.cn + 2) && get_next_line(fd, &line))
		i++;
	e->palette.i = e->palette.i < e->palette.pn ? e->palette.i + 1 : 0;
	i = -1;
	while (++i <= e->palette.cn && get_next_line(fd, &line))
		e->palette.c[i] = ft_strhextoi(line);
}
