/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 21:29:30 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/22 22:02:30 by wwatkins         ###   ########.fr       */
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
			e->pts[y][x].x = xoff + (x * 1.3 - y * 1.3) * e->zoom;
			e->pts[y][x].y = yoff + (y * 1.3 + x * 1.3) * e->zoom - (tab[y][x] * 4);
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
			if (x > 0)
				ft_drawline(*e, e->pts[y][x], e->pts[y][x - 1]);
			if (y > 0)
				ft_drawline(*e, e->pts[y][x], e->pts[y - 1][x]);
		}
	}
}

int		ft_expose_hook(t_env *e)
{
	ft_displaylines(e);
	return (1);
}

int		ft_loop_hook(t_env *e)
{
	ft_expose_hook(e);
	return (1);
}

int		ft_keyhook(int keycode, t_env *e)
{
	(keycode == 53 ? exit(0) : 0);
	printf("%d\n%d\n", keycode, e->color);
	return (1);
}

void	ft_core(t_env *e, int **tab)
{
	e->scw = 1440;
	e->sch = 1440;
	e->color = 0xECE9F1;
	ft_error((int)(e->mlx = mlx_init()));
	ft_error((int)(e->win = mlx_new_window(e->mlx, e->scw, e->sch, "Fdf")));
	ft_assigncoor(e, tab);
	mlx_expose_hook(e->win, ft_expose_hook, e);
	mlx_key_hook(e->win, ft_keyhook, e);
	mlx_loop_hook(e->mlx, ft_loop_hook, e);
	mlx_loop(e->mlx);
}
