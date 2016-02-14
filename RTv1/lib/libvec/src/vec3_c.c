/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 18:31:06 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/14 12:13:22 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

void	vec3_clamp(t_vec3 *v, double min, double max)
{
	v->x > max ? v->x = max : 0;
	v->y > max ? v->y = max : 0;
	v->z > max ? v->z = max : 0;
	v->x < min ? v->x = min : 0;
	v->y < min ? v->y = min : 0;
	v->z < min ? v->z = min : 0;
}

void	vec3_rotate(t_vec3 *v, t_vec3 r)
{
	vec3_rot(v, X, r.x);
	vec3_rot(v, Y, r.y);
	vec3_rot(v, Z, r.z);
}

t_vec3	vec3_cross(t_vec3 va, t_vec3 vb)
{
	t_vec3	v;

	v.x = va.y * vb.z - va.z * vb.y;
	v.y = va.z * vb.x - va.x * vb.z;
	v.z = va.x * vb.y - va.y * vb.x;
	return (v);
}

t_vec3	vec3_reflect(t_vec3 v, t_vec3 n)
{
	t_vec3	r;

	r = vec3_fmul(n, -2.0 * vec3_dot(v, n));
	r = vec3_add(r, v);
	return (r);
}

t_vec3	vec3_norm(t_vec3 v)
{
	t_vec3	n;
	double	magnitude;

	magnitude = vec3_magnitude(v);
	n.x = v.x / magnitude;
	n.y = v.y / magnitude;
	n.z = v.z / magnitude;
	return (n);
}
