/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:36:17 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/10 15:28:02 by wwatkins         ###   ########.fr       */
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
	e->ray.inshade = 0;
	if (ray_intersect(e, tmin, t) != obj)
	{
		e->ray.inshade = 1;
		e->color = vec3_fmul(e->color, 0.5);
	}
}

void	set_lambertian_shading(t_env *e, t_obj *obj)
{
	double	diff;
	double	coeff;

	diff = vec3_dot(e->ray.dir, obj->normal);
	diff < 0.0 ? diff = 0.0 : 0;
	coeff = (obj->mat.ambient + obj->mat.diffuse) * diff;
	e->color = vec3_fmul(vec3_mul(obj->color, e->lgt.color), coeff);
	vec3_clamp(&e->color, 0.0, 1.0);
}

void	set_blinn_phong_shading(t_env *e, t_obj *obj)
{
	t_vec3	lighdir;
	t_vec3	viewdir;
	t_vec3	halfdir;
	t_vec3	specular;
	float	spec;

	lighdir = vec3_sub(e->lgt.pos, e->ray.hit);
	vec3_normalize(&lighdir);
	viewdir = vec3_sub(e->cam.pos, e->ray.hit);
	vec3_normalize(&viewdir);
	halfdir = vec3_add(lighdir, viewdir);
	vec3_normalize(&halfdir);
	spec = pow(vec3_dot(obj->normal, halfdir), obj->mat.shininess);
	specular = vec3_fmul(e->lgt.color, spec * obj->mat.specular);
	if (!e->ray.inshade)
		e->color = vec3_add(e->color, vec3_mul(obj->color, specular));
	vec3_clamp(&e->color, 0.0, 1.0);
}

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
