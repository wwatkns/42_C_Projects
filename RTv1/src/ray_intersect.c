/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:10:36 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/09 08:05:56 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj	*ray_intersect(t_env *e, double *tmin)
{
	t_obj	*current;
	t_obj	*obj;
	double	t;

	obj = NULL;
	current = e->obj->next;
	while (current != NULL)
	{
		//current->type == CONE ? value = ray_intersect_cone(e, current) : 0;
		current->type == PLANE ? t = ray_intersect_plane(e, current) : 0;
		current->type == SPHERE ? t = ray_intersect_sphere(e, current) : 0;
		//current->type == CYLINDER ? value = ray_intersect_cylinder(e, current) : 0;
		if (t > 0.0 && t < *tmin)
		{
			obj = current;
			*tmin = t;
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
	double	h;
	t_vec3	len;

	len = vec3_sub(e->ray.pos, obj->pos);
	a = vec3_dot(e->ray.dir, e->ray.dir);
	b = vec3_dot(len, e->ray.dir);
	c = vec3_dot(len, len) - vec3_magnitude(obj->scale) * vec3_magnitude(obj->scale);
	h = b * b - a * c;
	if (h < 0.0)
		return (-1.0);
	return ((-b - sqrt(h)) / a);
}
