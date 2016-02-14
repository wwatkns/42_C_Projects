/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 12:52:47 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/14 09:08:12 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	core(t_env *e)
{
	error((int)(e->mlx = mlx_init()));
	error((int)(e->win.adr = mlx_new_window(e->mlx, e->win.w, e->win.h,
	e->arg.file_scene)));
	ft_strdel(&e->arg.file_scene);
	img_init(e);
	raytracing(e);
	mlx_hook(e->win.adr, 2, (1L << 0), key_pressed, e);
	mlx_expose_hook(e->win.adr, expose_hook, e);
	mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_loop(e->mlx);
}

void	env_init(t_env *e)
{
	t_obj	*obj;
	t_lgt	*light;

	error((int)(obj = (t_obj*)malloc(sizeof(t_obj))));
	error((int)(light = (t_lgt*)malloc(sizeof(t_lgt))));
	e->obj = obj;
	e->light = light;
	e->obj->next = NULL;
	e->light->next = NULL;
	e->win.w = e->arg.w;
	e->win.h = e->arg.h;
	e->win.dw = e->arg.w / 2;
	e->win.dh = e->arg.h / 2;
	e->recursiondepth = 0;
	e->shadow = 1.0;
}

void	cam_init(t_env *e)
{
	double	coeff;

	coeff = (e->win.w < e->win.h ? e->win.w : e->win.h);
	e->cam.w = e->win.w / coeff;
	e->cam.h = e->win.h / coeff;
	e->cam.dist = 1.0 / tan(e->cam.fov / 2.0 * DEG2RAD);
	e->cam.origin = vec3_sub(vec3_add(e->cam.pos,
				vec3_add(vec3_fmul(e->cam.dir, e->cam.dist),
				vec3_fmul(vec3_up(), e->cam.h / 2.0))),
				vec3_fmul(vec3_right(), e->cam.w / 2.0));
	e->cam.xi = e->cam.w / (double)e->win.w;
	e->cam.yi = e->cam.h / (double)e->win.h;
	e->cam.supersampling_inc = 1 / e->cam.supersampling;
	e->cam.supersampling_coeff = 1 / powf(e->cam.supersampling, 2);


}
