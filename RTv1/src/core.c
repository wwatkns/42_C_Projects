/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 12:52:47 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/28 15:32:49 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	core(t_env *e)
{
	env_init(e);
	error((int)(e->mlx = mlx_init()));
	error((int)(e->win.adr = mlx_new_window(e->mlx, e->win.w, e->win.h,
				"RTv1")));
	img_init(e);
	mlx_hook(e->win.adr, 2, (1L << 0), key_pressed, e);
	mlx_expose_hook(e->win.adr, expose_hook, e);
	mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_loop(e->mlx);
}

void	env_init(t_env *e)
{
	e->win.w = e->arg.w;
	e->win.h = e->arg.h;
}
