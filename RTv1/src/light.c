/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:36:17 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/10 11:08:21 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	set_light(t_env *e)
{
	e->ray.pos = e->lgt.pos;
	e->ray.dir = vec3_sub(e->ray.hit, e->lgt.pos);
	vec3_normalize(&e->ray.dir);
}

void	set_shadows(t_env *e, t_obj *obj, double *tmin, double *t)
{
	*tmin = INFINITY;
	if (ray_intersect(e, tmin, t) != obj)
		e->color = vec3_fmul(e->color, 0.5);
}

void	set_lambertian_shading(t_env *e, t_obj *obj)
{
	double	shade;
	double	ambient;
	double	diffuse;

	ambient = 0.15;
	diffuse = 1.0 - ambient;
	shade = vec3_dot(e->ray.dir, obj->normal);
	if (shade < 0.0)
		shade = 0.0;
	e->color = vec3_fmul(e->lgt.color, ambient + diffuse * shade);
	e->color = vec3_mul(e->color, obj->color);
	vec3_clamp(&e->color, 0.0, 1.0);
}

/*void	set_phong_shading(t_env *e, t_obj *obj)
{
	double	shade;

	shade = vec3_dot(e->ray.dir, obj->normal);
}*/

void	set_normal(t_env *e, t_obj *obj)
{
	obj->normal = vec3_sub(obj->pos, obj->dir); // incorrect
	if (obj->type == SPHERE)
		obj->normal = vec3_sub(obj->pos, e->ray.hit);
	if (obj->type == CYLINDER || obj->type == CONE)
		obj->normal = vec3(obj->pos.x - e->ray.hit.x, 0.0,
						obj->pos.z - e->ray.hit.z);
	vec3_normalize(&obj->normal);
}
