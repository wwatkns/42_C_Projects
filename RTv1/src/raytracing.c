/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 11:03:23 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/09 11:52:15 by wwatkins         ###   ########.fr       */
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
	e->ray.len = vec3(0, 0, 0);
	e->ray.dist = 0;
	e->ray.dir = vec3_add(e->cam.origin, vec3_sub(
				vec3_fmul(vec3_right(), e->cam.xi * e->ray.x),
				vec3_fmul(vec3_up(), e->cam.yi * e->ray.y)));
	vec3_normalize(&e->ray.dir);
}

void	raytracing_color(t_env *e, t_obj *obj, t_vec3 hit)
{
	t_obj	*other;
	double	tmin;
	double	t;

	tmin = INFINITY;
	e->ray.pos = e->lgt.pos;
	e->ray.dir = vec3_sub(hit, e->lgt.pos);
	vec3_normalize(&e->ray.dir);
	other = ray_intersect(e, &tmin, &t);
	if (other == obj)
		img_pixel_put(e, e->ray.x, e->ray.y, obj->rgb);
	else
		img_pixel_put(e, e->ray.x, e->ray.y, \
		set_rgb(obj->rgb.r / 2, obj->rgb.g / 2, obj->rgb.b / 2));
}

void	raytracing_draw(t_env *e)
{
	t_obj	*obj;
	t_vec3	hit;
	double	tmin;
	double	t;

	tmin = INFINITY;
	obj = ray_intersect(e, &tmin, &t);
	if (obj != NULL && tmin != INFINITY)
	{
		//hit = vec3_fmul(vec3_add(e->ray.pos, e->ray.dir), tmin);
		raytracing_color(e, obj, hit);
	}
}
