/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:36:17 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/09 19:35:41 by wwatkins         ###   ########.fr       */
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
		obj->color = vec3_fmul(obj->color, 0.5);
}

void	set_diffuse(t_env *e, t_obj *obj)
{
	double	angle;
	t_vec3	temp;

	temp = obj->color;
	angle = vec3_dot(e->ray.dir, obj->normal);
	if (angle <= 0)
		obj->color = vec3(0, 0, 0);
	else
		obj->color = vec3_fmul(e->lgt.color, 0.8 * angle);
	obj->color = vec3_add(vec3_fmul(temp, 0.5), obj->color);
	vec3_clamp(&obj->color, 0.0, 1.0);
}

void	set_normal(t_env *e, t_obj *obj)
{
	if (obj->type == PLANE)
		obj->normal = vec3_sub(obj->pos, obj->dir);
	if (obj->type == SPHERE)
		obj->normal = vec3_sub(obj->pos, e->ray.hit);
	if (obj->type == CYLINDER || obj->type == CONE)
		obj->normal = vec3(obj->pos.x - e->ray.hit.x, 0.0,
						obj->pos.z - e->ray.hit.z);
	vec3_normalize(&obj->normal);
}
