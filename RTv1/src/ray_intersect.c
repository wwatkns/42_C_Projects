/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:10:36 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/11 18:17:44 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj	*ray_intersect(t_env *e, double *tmin, double *t)
{
	t_obj	*current;
	t_obj	*obj;

	obj = NULL;
	current = e->obj->next;
	while (current != NULL)
	{
	//	vec3_rot(&e->ray.dir, Z, current->dir.x);
		current->type == CONE ? *t = ray_intersect_cone(e, current) : 0;
		current->type == PLANE ? *t = ray_intersect_plane(e, current) : 0;
		current->type == SPHERE ? *t = ray_intersect_sphere(e, current) : 0;
		current->type == CYLINDER ? *t = ray_intersect_cylinder(e, current) : 0;
	//	vec3_rot(&e->ray.dir, Z, -current->dir.x);
		if (*t > 0.0 && *t < *tmin)
		{
			obj = current;
			*tmin = *t;
		}
		current = current->next;
	}
	return (obj);
}

double	ray_intersect_plane(t_env *e, t_obj *obj)
{
	double	t;

	t = -((vec3_dot(obj->dir, e->ray.pos) - vec3_dot(obj->dir, obj->pos)) /
		vec3_dot(obj->dir, e->ray.dir));
	if (t < 0.0)
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
	if (disc < 0.0)
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
	if (disc < 0.0)
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
	if (disc < 0.0)
		return (-1.0);
	return ((-b - sqrt(disc)) / a);
}
