/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 11:03:23 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/09 17:05:03 by wwatkins         ###   ########.fr       */
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

void	raytracing_color(t_env *e, t_obj *obj, double *tmin, double *t)
{
	double	angle;

	*tmin = INFINITY;
	e->ray.pos = e->lgt.pos;
	e->ray.dir = vec3_sub(e->ray.hit, e->ray.pos);
	vec3_normalize(&e->ray.dir);

	angle = vec3_dot(e->ray.dir, vec3_sub(obj->pos, e->ray.hit)) * DEG2RAD;
//	printf("angle: %f\n", angle);

	if (angle <= 0)
		obj->rgb = set_rgb(obj->rgb.r / 2.0,
		obj->rgb.g / 2.0, obj->rgb.b / 2.0);
	else
		obj->rgb = set_rgb((e->lgt.rgb.r * 0.95 * angle) * 255 / 100,
							(e->lgt.rgb.g * 0.95 * angle) * 255 / 100,
							(e->lgt.rgb.b * 0.95 * angle) * 255 / 100);

	obj->rgb.r > e->lgt.rgb.r ? obj->rgb.r = e->lgt.rgb.r : 0;
	obj->rgb.g > e->lgt.rgb.g ? obj->rgb.g = e->lgt.rgb.g : 0;
	obj->rgb.b > e->lgt.rgb.b ? obj->rgb.b = e->lgt.rgb.b : 0;
	if (ray_intersect(e, tmin, t) == obj)
		img_pixel_put(e, e->ray.x, e->ray.y, obj->rgb);
	else
		img_pixel_put(e, e->ray.x, e->ray.y, \
		set_rgb(obj->rgb.r / 2.0, obj->rgb.g / 2.0, obj->rgb.b / 2.0));
}

void	raytracing_draw(t_env *e)
{
	t_obj	*obj;
	double	tmin;
	double	t;

	tmin = INFINITY;
	obj = ray_intersect(e, &tmin, &t);
	if (obj != NULL && tmin != INFINITY)
	{
		e->ray.hit = vec3_add(e->ray.pos, vec3_fmul(e->ray.dir, tmin));
		raytracing_color(e, obj, &tmin, &t);
	}
}
