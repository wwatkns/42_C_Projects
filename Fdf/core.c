/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 21:29:30 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/21 21:29:37 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_assigncoor(t_env e, t_point **pts, int **tab, int tabwidth)
{
	int x;
	int y;

	y = 0;
	ft_error((int)(pts = (t_point**)malloc(sizeof(t_point) * TAB_SIZE)));
	while (tab[y] != NULL)
	{
		x = 0;
		ft_error((int)(pts[y] = (t_point*)malloc(sizeof(t_point) * tabwidth)));
		while (x < tabwidth)
		{
			pts[y][x].x = (x * 1.5f - y * 1.5f) * 20 + 600;
			pts[y][x].y = (y * 1.5f + x * 1.5f) * 20 - (tab[y][x] * 4) + 200;
			if (x > 0)
				ft_drawline(e, ft_line(pts[y][x].x, pts[y][x].y,
				pts[y][x - 1].x, pts[y][x - 1].y), 0xFFFFFF - tab[y][x] * 10);
			if (y > 0)
				ft_drawline(e, ft_line(pts[y][x].x, pts[y][x].y,
				pts[y - 1][x].x, pts[y - 1][x].y), 0xFFFFFF - tab[y][x] * 10);
			x++;
		}
		y++;
	}
}

int		ft_keyhook(int keycode, t_env *e)
{
	(keycode == 53 ? exit(0) : 0);
	printf("%d\n", keycode);
	return (0);
}

void	ft_core(int **tab, int tabwidth)
{
	t_env	e;
	t_point	**pts;

	ft_error((int)(e.mlx = mlx_init()));
	ft_error((int)(e.win = mlx_new_window(e.mlx, 1280, 1280, "Fdf")));
	ft_assigncoor(e, pts, tab, tabwidth);
	mlx_key_hook(e.win, ft_keyhook, &e);
	mlx_loop(e.mlx);
}
