/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 11:03:23 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/12 14:50:35 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	raytracing(t_env *e)
{
	double	i;
	double	j;

	e->ray.y = -1;
	while (++e->ray.y < e->win.h)
	{
		e->ray.x = -1;
		while (++e->ray.x < e->win.w)
		{
			e->color_out = vec3(0.0, 0.0, 0.0);
			i = e->ray.x;
			while (i < e->ray.x + 1.0)
			{
				j = e->ray.y;
				while (j < e->ray.y + 1.0)
				{
					raytracing_init(e, i, j);
					raytracing_draw(e);
					j += e->cam.supersampling_inc;
				}
				i += e->cam.supersampling_inc;
			}
			e->cam.invgamma != 1.0 ? set_gamma(e) : 0;
			img_pixel_put(e, e->ray.x, e->ray.y, e->color_out);
		}
	}
}

void	raytracing_init(t_env *e, double i, double j)
{
	e->ray.pos = e->cam.pos;
	e->ray.dir = e->cam.origin;
	e->ray.hit = vec3(0, 0, 0);
	e->ray.dir = vec3_add(e->cam.origin, vec3_sub(
				vec3_fmul(vec3_right(), e->cam.xi * i),
				vec3_fmul(vec3_up(), e->cam.yi * j)));
	vec3_normalize(&e->ray.dir);
}

void	raytracing_color(t_env *e, t_obj *obj, double *tmin, double *t)
{
	t_vec3	ambient;
	t_vec3	diffuse;
	t_vec3	specular;
	t_lgt	*light;

	light = e->light;
	e->color = vec3(0, 0, 0);
	while ((light = light->next) != NULL)
	{
		set_light(e, light);
		set_normal(e, obj);
		set_shadows(e, obj, tmin, t);
		ambient = vec3_fmul(light->color, obj->mat.ambient);
		diffuse = set_diffuse(e, obj, light);
		specular = set_specular(e, obj, light);
		e->color_t = vec3_add(ambient, vec3_add(diffuse, specular));
		e->color_t = vec3_fmul(e->color_t, light->intensity);
		e->color = vec3_fmul(vec3_add(e->color,
				vec3_mul(obj->mat.color, e->color_t)), e->shadow);
		vec3_clamp(&e->color, 0, 1);
	}
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
		e->color_out = vec3_add(e->color_out,
		vec3_fmul(e->color, e->cam.supersampling_coeff));
	}
	else
		e->color = vec3(0, 0, 0);
}
