/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 21:29:30 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/22 17:55:27 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_assigncoor(t_env *e, int **tab)
{
	int x;
	int y;

	y = -1;
	ft_error((int)(e->pts = (t_ptcol**)malloc(sizeof(t_point) * e->gh)));
	while (++y < e->gh)
	{
		x = -1;
		ft_error((int)(e->pts[y] = (t_ptcol*)malloc(sizeof(t_point) * e->gw)));
		while (++x < e->gw)
		{
			e->pts[y][x].x = 600 + (x * 1.5 - y * 1.5) * 20;
			e->pts[y][x].y = 200 + (y * 1.3 + x * 1.3) * 20 - (tab[y][x] * 4);
			e->pts[y][x].c = 0x999999 - tab[y][x] * 10;
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
			if (x > 0)
				ft_drawline(*e, e->pts[y][x], e->pts[y][x - 1], e->pts[y][x].c);
			if (y > 0)
				ft_drawline(*e, e->pts[y][x], e->pts[y - 1][x], e->pts[y][x].c);
		}
	}
}

int		ft_loop(t_env *e)
{
	ft_displaylines(e);
	mlx_do_sync(e->mlx);
	return (0);
}

int		ft_keyhook(int keycode, t_env *e)
{
	(keycode == 53 ? exit(0) : 0);
	printf("%d\n", keycode);
	return (0);
}

void	ft_core(t_env *e, int **tab)
{
	ft_error((int)(e->mlx = mlx_init()));
	ft_error((int)(e->win = mlx_new_window(e->mlx, 2560, 1440, "Fdf")));
	ft_assigncoor(e, tab);
	mlx_key_hook(e->win, ft_keyhook, &e);
	mlx_loop_hook(e->mlx, ft_loop, e);
	mlx_loop(e->mlx);
}
