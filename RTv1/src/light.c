/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:36:17 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/10 13:04:06 by wwatkins         ###   ########.fr       */
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
	double	coeff;

	shade = vec3_dot(e->ray.dir, obj->normal);
	if (shade < 0.0)
		shade = 0.0;
	coeff = obj->mat.ambient + obj->mat.diffuse * shade;
	e->color = vec3_fmul(vec3_mul(obj->color, e->lgt.color), coeff);
	vec3_clamp(&e->color, 0.0, 1.0);
}

/*void	set_phong_shading(t_env *e, t_obj *obj)
{
	double	shade;
	double	coeff;
	double	dot;
	t_vec3	refl;

	coeff = 0.0;
	shade = -vec3_dot(e->ray.dir, obj->normal);
	refl = vec3_sub(e->ray.dir, vec3_fmul(obj->normal, 2.0 * shade));
	dot = vec3_dot(e->cam.dir, refl);
	if (dot < 0.0)
		coeff = 0.0;
	coeff = dot * obj->mat.specular * obj->mat.diffuse + obj->mat.ambient;
	e->color = vec3_fmul(vec3_mul(e->lgt.color, obj->color), coeff);
	vec3_clamp(&e->color, 0.0, 1.0);
}*/

void	set_phong_shading(t_env *e, t_obj *obj)
{
	t_vec3	viewdir;
	t_vec3	halfdir;
	t_vec3	specular;
	float	spec;

	viewdir = vec3_sub(e->cam.pos, e->ray.hit);
	halfdir = vec3_add(e->ray.dir, viewdir);
	vec3_normalize(&viewdir);
	vec3_normalize(&halfdir);
	spec = pow(vec3_dot(obj->normal, halfdir), 20.0);
	specular = vec3_fmul(e->lgt.color, spec);
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
