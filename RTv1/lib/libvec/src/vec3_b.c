/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 10:57:57 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/14 12:37:02 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	vec3_add(t_vec3 va, t_vec3 vb)
{
	t_vec3	v;

	v.x = va.x + vb.x;
	v.y = va.y + vb.y;
	v.z = va.z + vb.z;
	return (v);
}

t_vec3	vec3_sub(t_vec3 va, t_vec3 vb)
{
	t_vec3	v;

	v.x = va.x - vb.x;
	v.y = va.y - vb.y;
	v.z = va.z - vb.z;
	return (v);
}

t_vec3	vec3_mul(t_vec3 va, t_vec3 vb)
{
	t_vec3	v;

	v.x = va.x * vb.x;
	v.y = va.y * vb.y;
	v.z = va.z * vb.z;
	return (v);
}

double	vec3_dot(t_vec3 va, t_vec3 vb)
{
	return ((va.x * vb.x + va.y * vb.y + va.z * vb.z));
}

void	vec3_rot(t_vec3 *v, int axis, double theta)
{
	t_vec3	r;

	theta *= DEG2RAD;
	r = (t_vec3) { v->x, v->y, v->z };
	if (axis == Z)
	{
		r.x = v->x * cos(theta) - v->y * sin(theta);
		r.y = v->x * sin(theta) + v->y * cos(theta);
	}
	if (axis == Y)
	{
		r.x = v->x * cos(theta) - v->z * sin(theta);
		r.z = v->x * sin(theta) + v->z * cos(theta);
	}
	if (axis == X)
	{
		r.y = v->y * cos(theta) - v->z * sin(theta);
		r.z = v->y * sin(theta) + v->z * cos(theta);
	}
	*v = r;
}
