/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:55:09 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/22 14:49:20 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	core(t_env *e)
{
	env_init(e);
	map_init(e);
	error((int)(e->mlx = mlx_init()));
	error((int)(e->win = mlx_new_window(e->mlx, e->win_w, e->win_h,
	"wolf3d")));
	img_init(e);
	mlx_hook(e->win, 2, (1L << 0), key_pressed, e);
	mlx_hook(e->win, 3, (1L << 1), key_released, e);
	mlx_hook(e->win, 6, (1L << 6), mouse_pos, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_loop(e->mlx);
}

void	env_init(t_env *e)
{
	e->win_w = e->arg.w;
	e->win_h = e->arg.h;
	e->cam.pos.x = e->win_w / 2;
	e->cam.pos.y = e->win_h / 2;
	e->cam.fov = FOV;
	e->cam.dir = vec2(0, -1);
	e->cam.pln = vec2(1, 0);
	e->map.pos = vec2(10, 10);
	e->key.w = 0;
	e->key.s = 0;
	e->key.a = 0;
	e->key.d = 0;
	e->key.q = 0;
	e->key.e = 0;
}
