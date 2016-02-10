/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 11:03:23 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/10 10:50:53 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	raytracing(t_env *e)
{
	e->ray.y = 0;
	while (e->ray.y < e->win.h)
	{
		e->ray.x = 0;
		while (e->ray.x < e->win.w)
		{
			raytracing_init(e);
			raytracing_draw(e);
			e->ray.x++;
		}
		e->ray.y++;
	}
}

void	raytracing_init(t_env *e)
{
	e->ray.pos = e->cam.pos;
	e->ray.dir = e->cam.origin;
	e->ray.hit = vec3(0, 0, 0);
	e->ray.dist = 0;
	e->ray.dir = vec3_add(e->cam.origin, vec3_sub(
				vec3_fmul(vec3_right(), e->cam.xi * e->ray.x),
				vec3_fmul(vec3_up(), e->cam.yi * e->ray.y)));
	vec3_normalize(&e->ray.dir);
}

t_vec3	raytracing_color(t_env *e, t_obj *obj, t_vec3 color, double *tmin, double *t)
{
	set_light(e);
	set_normal(e, obj);
	color = obj->color;
	color = set_lambertian_shading(e, obj);
	color = set_shadows(e, obj, color, tmin, t);
	vec3_clamp(&color, 0.0, 1.0);
	return (color);
}

void	raytracing_draw(t_env *e)
{
	t_obj	*obj;
	t_vec3	color;
	double	tmin;
	double	t;

	tmin = INFINITY;
	obj = ray_intersect(e, &tmin, &t);
	if (obj != NULL && tmin != INFINITY)
	{
		e->ray.hit = vec3_add(e->ray.pos, vec3_fmul(e->ray.dir, tmin));
		color = raytracing_color(e, obj, color, &tmin, &t);
		img_pixel_put(e, e->ray.x, e->ray.y, color);
	}
}
