/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 21:29:30 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/03 18:58:19 by wwatkins         ###   ########.fr       */
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
	ft_error((int)(e->pts = (t_point**)malloc(sizeof(t_point) * e->gh)));
	while (++y < e->gh)
	{
		x = -1;
		ft_error((int)(e->pts[y] = (t_point*)malloc(sizeof(t_point) * e->gw)));
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
	int	color;

	y = -1;
	color = e->color;
	while (++y < e->gh)
	{
		x = -1;
		while (++x < e->gw)
		{
			e->pts[y][x].x += e->cam.move.x;
			e->pts[y][x].y += e->cam.move.y;
			x > 0 ? ft_drawline(*e, e->pts[y][x], e->pts[y][x - 1], color) : 0;
			y > 0 ? ft_drawline(*e, e->pts[y][x], e->pts[y - 1][x], color) : 0;
		}
	}
}

void	ft_initenv(t_env *e)
{
	e->scw = 1300;
	e->sch = 1300;
	e->ir = 2;
	e->key.w = 0;
	e->key.s = 0;
	e->key.a = 0;
	e->key.d = 0;
	e->color = 0xECE9F1;
}

void	ft_core(t_env *e, int **tab)
{
	ft_initenv(e);
	ft_error((int)(e->mlx = mlx_init()));
	ft_error((int)(e->win = mlx_new_window(e->mlx, e->scw, e->sch, "Fdf")));
	ft_assigncoor(e, tab);
	mlx_hook(e->win, 2, (1L << 0), ft_keyhook_pressed, e);
	mlx_hook(e->win, 3, (1L << 1), ft_keyhook_release, e);
	mlx_loop_hook(e->mlx, ft_loophook, e);
	mlx_expose_hook(e->win, ft_exposehook, e);
	mlx_loop(e->mlx);
}
