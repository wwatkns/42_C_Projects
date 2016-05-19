/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 11:03:23 by wwatkins          #+#    #+#             */
/*   Updated: 2016/03/11 15:12:00 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	raytracing(t_env *e)
{
	e->ray.y = -1;
	while (++e->ray.y < e->win.h)
	{
		e->ray.x = -1;
		while (++e->ray.x < e->win.w)
		{
			e->color_out = vec3_zero();
			e->i = e->ray.x;
			while (e->i < e->ray.x + 1.0)
			{
				e->j = e->ray.y;
				while (e->j < e->ray.y + 1.0)
				{
					raytracing_init(e);
					raytracing_draw(e);
					e->j += e->cam.supersampling_inc;
				}
				e->i += e->cam.supersampling_inc;
			}
			e->cam.invgamma != 1.0 ? set_gamma(e) : 0;
			img_pixel_put(e, e->ray.x, e->ray.y, e->color_out);
		}
		e->ray.y % e->loading == 0 ? disp_loading(e) : 0;
	}
}

void	raytracing_init(t_env *e)
{
	e->recursiondepth = 0;
	e->ray.pos = e->cam.pos;
	e->ray.dir = e->cam.origin;
	e->ray.hit = vec3_zero();
	e->ray.dir = vec3_add(e->cam.origin, vec3_sub(
				vec3_fmul(vec3_right(), e->cam.xi * e->i),
				vec3_fmul(vec3_up(), e->cam.yi * e->j)));
	vec3_rotate(&e->ray.dir, e->cam.rot);
	vec3_normalize(&e->ray.dir);
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
		raytracing_reflect(e, obj);
		raytracing_color(e, obj, &tmin, &t);
	}
	else
		e->color = vec3_zero();
	e->color_out = vec3_add(e->color_out,
	vec3_fmul(e->color, e->cam.supersampling_coeff));
	vec3_clamp(&e->color_out, 0, 1);
}

void	raytracing_reflect(t_env *e, t_obj *obj)
{
	if (e->recursiondepth < e->cam.maxdepth)
	{
		e->ray.pos = e->ray.hit;
		set_normal(e, obj);
		e->ray.dir = vec3_reflect(e->ray.dir, obj->normal);
		e->recursiondepth++;
		raytracing_draw(e);
	}
	else
		e->recursiondepth = 0;
}

void	raytracing_color(t_env *e, t_obj *obj, double *tmin, double *t)
{
	t_vec3	ambient;
	t_vec3	diffuse;
	t_vec3	specular;
	t_lgt	*light;

	light = e->light;
	e->color = vec3_zero();
	while ((light = light->next) != NULL)
	{
		set_light(e, light);
		set_normal(e, obj);
		set_shadows(e, obj, tmin, t);
		light->atenuation = 1.0 / (light->constant + light->linear *
			*tmin + light->quadratic * (*tmin * *tmin));
		ambient = vec3_fmul(light->color, obj->mat.ambient);
		diffuse = set_diffuse(e, obj, light);
		specular = set_specular(e, obj, light);
		e->color_t = vec3_add(ambient, vec3_add(diffuse, specular));
		e->color_t = vec3_fmul(e->color_t, light->atenuation);
		e->color_t = vec3_fmul(e->color_t, e->shadow);
		e->color_t = vec3_mul(e->color_t, obj->mat.color);
		e->color = vec3_add(e->color, e->color_t);
	}
}
