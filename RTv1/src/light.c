/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:36:17 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/12 18:30:06 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	set_light(t_env *e, t_lgt *light)
{
	e->ray.pos = light->pos;
	e->ray.dir = vec3_sub(e->ray.hit, light->pos);
	vec3_normalize(&e->ray.dir);
}

void	set_shadows(t_env *e, t_obj *obj, double *tmin, double *t)
{
	e->shadow = 1.0;
	*tmin = INFINITY;
	if (ray_intersect(e, tmin, t) != obj)
		e->shadow = 0.5;
}

t_vec3	set_diffuse(t_env *e, t_obj *obj, t_lgt *light)
{
	double	diff;

	diff = vec3_dot(e->ray.dir, obj->normal);
	diff < 0.0 ? diff = 0.0 : 0;
	return (vec3_fmul(light->color, diff * obj->mat.diffuse));
}

t_vec3	set_specular(t_env *e, t_obj *obj, t_lgt *light)
{
	t_vec3	lighdir;
	t_vec3	viewdir;
	t_vec3	halfdir;
	float	spec;

	lighdir = vec3_norm(vec3_sub(light->pos, e->ray.hit));
	viewdir = vec3_norm(vec3_sub(e->cam.pos, e->ray.hit));
	halfdir = vec3_norm(vec3_add(lighdir, viewdir));
	spec = pow(vec3_dot(obj->normal, halfdir), obj->mat.shininess);
	return (vec3_fmul(light->color, spec * obj->mat.specular));
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
