/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 21:29:30 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/23 12:28:44 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_assigncoor(t_env *e, int **tab)
{
	int x;
	int y;
	int xoff;
	int yoff;

	e->zoom = (e->scw < e->sch ? e->sch : e->scw) /
		(e->gw < e->gh ? e->gh : e->gw) / 2 * 0.6f;
	xoff = ((e->scw / 2) - (e->gw * e->zoom)) * 2;
	yoff = ((e->sch / 2) - (e->gh * e->zoom)) / 2;
	y = -1;
	ft_error((int)(e->pts = (t_point**)malloc(sizeof(t_point) * e->gh)));
	while (++y < e->gh)
	{
		x = -1;
		ft_error((int)(e->pts[y] = (t_point*)malloc(sizeof(t_point) * e->gw)));
		while (++x < e->gw)
		{
			e->pts[y][x].x = xoff + (x * 1.3 - y * 1.5) * e->zoom;
			e->pts[y][x].y = yoff + (y * 1.5 + x * 1.3) * e->zoom - (tab[y][x] * 4);
			e->pts[y][x].h = tab[y][x];
		}
	}
}

void	ft_displaylines(t_env *e)
{
	int x;
	int y;
	int color;

	y = -1;
	color = e->color;
	while (++y < e->gh)
	{
		x = -1;
		while (++x < e->gw)
		{
			e->color = color + e->pts[y][x].h * 10;
			e->pts[y][x].x += e->move.x;
			e->pts[y][x].y += e->move.y;
			e->pts[y][x].x *= e->zoom;
			e->pts[y][x].y *= e->zoom;
			if (x > 0)
				ft_drawline(*e, e->pts[y][x], e->pts[y][x - 1]);
			if (y > 0)
				ft_drawline(*e, e->pts[y][x], e->pts[y - 1][x]);
		}
	}
}

void	ft_initenv(t_env *e)
{
	e->scw = 1280;
	e->sch = 1280;
	e->key.u = 0;
	e->key.d = 0;
	e->key.l = 0;
	e->key.r = 0;
	e->key.zp = 0;
	e->key.zm = 0;
	e->move.x = 0;
	e->move.y = 0;
	e->zoom = 1;
	e->color = 0xECE9F1;
}

void	ft_core(t_env *e, int **tab)
{
	ft_initenv(e);
	ft_assigncoor(e, tab);
	ft_error((int)(e->mlx = mlx_init()));
	ft_error((int)(e->win = mlx_new_window(e->mlx, e->scw, e->sch, "Fdf")));
	//mlx_expose_hook(e->win, ft_expose_hook, e);
	mlx_hook(e->win, 2, 1L<<0, ft_keyhook_pressed, e);
	mlx_hook(e->win, 3, 1L<<1, ft_keyhook_release, e);
	mlx_loop_hook(e->mlx, ft_loophook, e);
	mlx_loop(e->mlx);
}
