/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 21:29:30 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/22 16:42:26 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_assigncoor(t_env *env, int **tab)
{
	int x;
	int y;

	y = 0;
	ft_error((int)(env->pts = (t_point**)malloc(sizeof(t_point) * env->grid_h)));
	while (y < env->grid_h)
	{
		x = 0;
		ft_error((int)(env->pts[y] = (t_point*)malloc(sizeof(t_point) *
		env->grid_w)));
		while (x < env->grid_w)
		{
			env->pts[y][x].x = (x * 1.2 - y * 1.5) * 5 + 700;
			env->pts[y][x].y = (y * 1.2 + x * 1.5) * 5 - (tab[y][x] * 4) - 800;
			x++;
		}
		y++;
	}
}

void	ft_displines(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (y < env->grid_h)
	{
		x = 0;
		while (x < env->grid_w)
		{
			if (x > 0)
				ft_drawline(*env, ft_line(env->pts[y][x].x, env->pts[y][x].y,
				env->pts[y][x - 1].x, env->pts[y][x - 1].y), 0xE5C1A);
			if (y > 0)
				ft_drawline(*env, ft_line(env->pts[y][x].x, env->pts[y][x].y,
				env->pts[y - 1][x].x, env->pts[y - 1][x].y), 0xE5C1A);
			x++;
		}
		y++;
	}
}

int		ft_loop(t_env *env)
{
	printf("ok");
	ft_displines(env);
	mlx_do_sync(env->mlx);
	return (0);
}

int		ft_keyhook(int keycode, t_env *env)
{
	(keycode == 53 ? exit(0) : 0);
	printf("%d\n", keycode);
	return (0);
}

void	ft_core(t_env *env, int **tab)
{
	ft_error((int)(env->mlx = mlx_init()));
	ft_error((int)(env->win = mlx_new_window(env->mlx, 2560, 1440, "Fdf")));
	ft_assigncoor(env, tab);
	mlx_key_hook(env->win, ft_keyhook, &env);
	mlx_loop_hook(env->mlx, ft_loop, env);
	mlx_loop(env->mlx);
}
