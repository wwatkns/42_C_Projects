/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 11:56:57 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/10 10:59:17 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawline(t_env *e, t_point p, t_point p1)
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
		ft_imgpixelput(e, p.x, p.y, ft_getcolor(e, p, p1));
		e2 = err + err;
		e2 > -d.y ? err -= d.y : 0;
		e2 > -d.y ? p.x += s.x : 0;
		e2 < d.x ? err += d.x : 0;
		e2 < d.x ? p.y += s.y : 0;
	}
}

void	ft_imgpixelput(t_env *e, int x, int y, int *rgb)
{
	int	pos;

	if (x >= 0 && x < e->scw && y >= 0 && y < e->sch)
	{
		pos = (x * e->img.bpp / 8) + (y * e->img.sl);
		e->img.img[pos] = rgb[0];
		e->img.img[pos + 1] = rgb[1];
		e->img.img[pos + 2] = rgb[2];
	}
	ft_memdel((void**)&rgb);
}

int		ft_setindex(t_env *e, t_point p, t_point p1)
{
	float	h;
	float	i;

	h = (float)(p.h + p1.h) / 2.0f;
	//i = ((float)p.h / (e->maxh)) * e->palette.cn + e->palette.step;
	//i = (((float)p.h + ABS(e->minh)) / (e->maxh - e->minh)) * e->palette.cn + e->palette.step; for neg values
	i = (h / (e->maxh - e->minh)) * e->palette.cn + e->palette.step;
	i > e->palette.cn ? i = e->palette.cn : 0;
	return (i > 0 ? i : 0);
}

int		*ft_getcolor(t_env *e, t_point p, t_point p1)
{
	int	n;
	int	*rgb;

	n = ft_setindex(e, p, p1);
	rgb = (int*)malloc(sizeof(int) * 3);
	rgb[0] = e->palette.c[n] % 256;
	rgb[1] = (e->palette.c[n] >> 8) % 256;
	rgb[2] = (e->palette.c[n] >> 16) % 256;
	return (rgb);
}

void	ft_setpalette(t_env *e)
{
	int		i;
	int		fd;
	char	*line;

	e->key.p = 0;
	i = 0;
	ft_error((fd = open(e->arg.pal, O_RDWR)));
	ft_error((get_next_line(fd, &line)));
	e->palette.pn = ft_atoi(line) - 1;
	ft_error((get_next_line(fd, &line)));
	e->palette.cn = ft_atoi(line) - 1;
	e->palette.c = (int*)malloc(sizeof(int) * e->palette.cn + 1);
	while (i < e->palette.i * (e->palette.cn + 2) && get_next_line(fd, &line))
		i++;
	e->palette.i = e->palette.i < e->palette.pn ? e->palette.i + 1 : 0;
	i = -1;
	while (++i < e->palette.cn + 1 && get_next_line(fd, &line))
		e->palette.c[i] = ft_strhextoi(line);
	free(line);
}
