/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 12:52:47 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/09 08:10:30 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	core(t_env *e)
{
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
	t_obj	*obj;

	error((int)(obj = (t_obj*)malloc(sizeof(t_obj))));
	e->obj = obj;
	e->obj->next = NULL;
	e->win.w = e->arg.w;
	e->win.h = e->arg.h;
	e->win.dw = e->arg.w / 2;
	e->win.dh = e->arg.h / 2;
}

void	cam_init(t_env *e)
{
	e->cam.dist = 1.0;
	e->cam.w = 0.5;
	e->cam.h = 0.35;
	e->cam.origin = vec3_sub(vec3_add(e->cam.pos,
				vec3_add(vec3_fmul(e->cam.dir, e->cam.dist),
				vec3_fmul(vec3_up(), e->cam.h / 2.0))),
				vec3_fmul(vec3_right(), e->cam.w / 2.0));
	e->cam.xi = e->cam.w / (double)e->win.w;
	e->cam.yi = e->cam.h / (double)e->win.h;
}
