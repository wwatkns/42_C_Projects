/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayintersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 17:05:08 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/13 17:05:13 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj	*ray_intersect(t_env *e, double *tmin, double *t)
{
	t_obj	*obj;
	t_obj	*out;

	obj = e->obj;
	while ((obj = obj->next) != NULL)
	{
		obj->type == CONE ? *t = ray_intersect_cone(e, obj) : 0;
		obj->type == PLANE ? *t = ray_intersect_plane(e, obj) : 0;
		obj->type == SPHERE ? *t = ray_intersect_sphere(e, obj) : 0;
		obj->type == CYLINDER ? *t = ray_intersect_cylinder(e, obj) : 0;
		if (*t > EPSILON && *t < *tmin)
		{
			out = obj;
			*tmin = *t;
		}
	}
	return (out);
}

double	ray_intersect_plane(t_env *e, t_obj *obj)
{
	double	t;

	t = -((vec3_dot(obj->dir, e->ray.pos) - vec3_dot(obj->dir, obj->pos)) /
		vec3_dot(obj->dir, e->ray.dir));
	if (t < EPSILON)
		return (-1.0);
	return (t);
}

double	ray_intersect_sphere(t_env *e, t_obj *obj)
{
	double	a;
	double	b;
	double	c;
	double	disc;
	t_vec3	len;

	len = vec3_sub(e->ray.pos, obj->pos);
	a = vec3_dot(e->ray.dir, e->ray.dir);
	b = vec3_dot(len, e->ray.dir);
	c = vec3_dot(len, len) - obj->scale;
	disc = b * b - a * c;
	if (disc < EPSILON)
		return (-1.0);
	return ((-b - sqrt(disc)) / a);
}

double	ray_intersect_cone(t_env *e, t_obj *obj)
{
	double	a;
	double	b;
	double	c;
	double	disc;
	t_vec3	len;

	len = vec3_sub(e->ray.pos, obj->pos);
	a = e->ray.dir.x * e->ray.dir.x - e->ray.dir.y * e->ray.dir.y +
		e->ray.dir.z * e->ray.dir.z;
	b = e->ray.dir.x * len.x - e->ray.dir.y * len.y +
		e->ray.dir.z * len.z;
	c = len.x * len.x + len.z * len.z - len.y * len.y;
	disc = b * b - a * c;
	if (disc < EPSILON)
		return (-1.0);
	return ((-b - sqrt(disc)) / a);
}

double	ray_intersect_cylinder(t_env *e, t_obj *obj)
{
	double	a;
	double	b;
	double	c;
	double	disc;
	t_vec3	len;

	len = vec3_sub(e->ray.pos, obj->pos);
	a = e->ray.dir.x * e->ray.dir.x + e->ray.dir.z * e->ray.dir.z;
	b = (e->ray.dir.x * len.x + e->ray.dir.z * len.z);
	c = len.x * len.x + len.z * len.z - obj->scale;
	disc = b * b - a * c;
	if (disc < EPSILON)
		return (-1.0);
	return ((-b - sqrt(disc)) / a);
}
