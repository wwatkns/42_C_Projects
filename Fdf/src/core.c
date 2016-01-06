/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 21:29:30 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/06 12:42:28 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_assigncoor(t_env *e, int **tab)
{
	int x;
	int y;
	int diffx;
	int diffy;

	diffx = (e->scw <= e->sch ? 0 : ABS((e->scw - e->sch)));
	diffy = (e->scw <= e->sch ? ABS((e->scw - e->sch)) : 0);
	e->cam.zoom = (e->scw < e->sch ? e->scw : e->sch) / (e->gw * e->ir + e->gh);
	e->cam.x = (e->gh * e->ir + e->gw) * e->cam.zoom / 2 + diffx / 2;
	e->cam.y = (e->gh + e->gw) * e->cam.zoom / 2 + diffy / 2;
	y = -1;
	ft_error((int)(e->pts = (t_point**)malloc(sizeof(t_point) * (e->gh + 1))));
	while (++y < e->gh)
	{
		x = -1;
		ft_error((int)(e->pts[y] = (t_point*)malloc(sizeof(t_point) * (e->gw + 1))));
		while (++x < e->gw)
		{
			e->pts[y][x].x = e->cam.x + (x - y) * e->cam.zoom;
			e->pts[y][x].y = e->cam.y + (x + y) * e->cam.zoom / e->ir;
			e->pts[y][x].y -= tab[y][x] * e->cam.zoom / 4;
			e->pts[y][x].h = tab[y][x];
		}
	}
}

void	ft_displaylines(t_env *e)
{
	int x;
	int y;

	y = -1;
	while (++y < e->gh)
	{
		x = -1;
		while (++x < e->gw)
		{
			if (e->key.w || e->key.s || e->key.a || e->key.d ||
				e->key.i || e->key.k || e->key.kp || e->key.km)
			{
				e->pts[y][x].x = e->cam.x + (x - y) * e->cam.zoom;
				e->pts[y][x].y = e->cam.y + (x + y) * e->cam.zoom / e->ir;
				e->pts[y][x].y -= e->pts[y][x].h * (e->cam.alt + 1) *
								e->cam.zoom / 4;
			}
			x > 0 ? ft_drawline(*e, e->pts[y][x], e->pts[y][x - 1]) : 0;
			y > 0 ? ft_drawline(*e, e->pts[y][x], e->pts[y - 1][x]) : 0;
		}
	}
}

void	ft_initimg(t_env *e)
{
	ft_error((int)(e->img.adr = mlx_new_image(e->mlx, e->scw, e->sch)));
	e->img.img = mlx_get_data_addr(e->img.adr, &e->img.bpp,
								&e->img.sl, &e->img.endian);
}

void	ft_initenv(t_env *e)
{
	e->scw = e->arg.w;
	e->sch = e->arg.h;
	e->ir = 2;
	e->cam.alt = 0;
	e->key.w = 0;
	e->key.s = 0;
	e->key.a = 0;
	e->key.d = 0;
	e->key.i = 0;
	e->key.k = 0;
	e->key.p = 0;
	e->key.kp = 0;
	e->key.km = 0;
	e->palette.i = 0;
}

void	ft_core(t_env *e, int **tab)
{
	ft_initenv(e);
	ft_setpalette(e);
	ft_error((int)(e->mlx = mlx_init()));
	ft_error((int)(e->win = mlx_new_window(e->mlx, e->scw, e->sch,
					e->arg.map)));
	ft_initimg(e);
	ft_assigncoor(e, tab);
	mlx_hook(e->win, 2, (1L << 0), ft_keyhook_pressed, e);
	mlx_hook(e->win, 3, (1L << 1), ft_keyhook_release, e);
	mlx_loop_hook(e->mlx, ft_loophook, e);
	mlx_expose_hook(e->win, ft_exposehook, e);
	mlx_loop(e->mlx);
}
