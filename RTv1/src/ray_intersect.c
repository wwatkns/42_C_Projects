/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:10:36 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/09 13:23:57 by wwatkins         ###   ########.fr       */
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
		current->type == PLANE ? *t = ray_intersect_plane(e, current) : 0;
		current->type == SPHERE ? *t = ray_intersect_sphere(e, current) : 0;
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
	double	v;
	double	h;
	double	d;
	double	r;
	t_vec3	len;

	len = vec3_sub(e->ray.pos, obj->pos);
	v = vec3_dot(len, e->ray.dir);
	r = vec3_magnitude(obj->scale);
	h = r * r - (vec3_dot(len, len) - v * v);
	if (h < 0.0)
		return (-1.0);
	d = sqrt(h);
	return ((-v - d) / vec3_dot(e->ray.dir, e->ray.dir));
}

/*double	ray_intersect_sphere(t_env *e, t_obj *obj)
{
	double	a;
	double	b;
	double	c;
	double	h;
	t_vec3	len;

	len = vec3_sub(e->ray.pos, obj->pos);
	a = vec3_dot(e->ray.dir, e->ray.dir);
	b = vec3_dot(len, e->ray.dir);
	c = vec3_dot(len, len) - vec3_magnitude(vec3_mul(obj->scale, obj->scale));
	h = b * b - a * c;
	if (h < 0.0)
		return (-1.0);
	return ((-b - sqrt(h)) / a);
}*/
