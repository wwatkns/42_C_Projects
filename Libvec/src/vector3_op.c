/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 10:57:57 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/27 16:27:34 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	vec3_add(t_vec3 vec3a, t_vec3 vec3b)
{
	t_vec3	vec3;

	vec3.x = vec3a.x + vec3b.x;
	vec3.y = vec3a.y + vec3b.y;
	vec3.z = vec3a.z + vec3b.z;
	return (vec3);
}

t_vec3	vec3_sub(t_vec3 vec3a, t_vec3 vec3b)
{
	t_vec3	vec3;

	vec3.x = vec3a.x - vec3b.x;
	vec3.y = vec3a.y - vec3b.y;
	vec3.z = vec3a.z - vec3b.z;
	return (vec3);
}

t_vec3	vec3_mul(t_vec3 vec3a, t_vec3 vec3b)
{
	t_vec3	vec3;

	vec3.x = vec3a.x * vec3b.x;
	vec3.y = vec3a.y * vec3b.y;
	vec3.z = vec3a.z * vec3b.z;
	return (vec3);
}

float	vec3_dot(t_vec3 vec3a, t_vec3 vec3b)
{
	return ((vec3a.x * vec3b.x + vec3a.y * vec3b.y + vec3a.z * vec3b.z));
}

void	vec3_rot(t_vec3 *vec3, int axis, float theta)
{
	t_vec3	vec3t;

	theta *= DEG2RAD;
	vec3t = (t_vec3) { vec3->x, vec3->y, vec3->z };
	if (axis == Z)
	{
		vec3t.x = vec3->x * cos(theta) - vec3->y * sin(theta);
		vec3t.y = vec3->x * sin(theta) + vec3->y * cos(theta);
	}
	if (axis == Y)
	{
		vec3t.x = vec3->x * cos(theta) - vec3->z * sin(theta);
		vec3t.z = vec3->x * sin(theta) + vec3->z * cos(theta);
	}
	if (axis == X)
	{
		vec3t.y = vec3->y * cos(theta) - vec3->z * sin(theta);
		vec3t.z = vec3->y * sin(theta) + vec3->z * cos(theta);
	}
	vec3->x = vec3t.x;
	vec3->y = vec3t.y;
	vec3->z = vec3t.z;
}
