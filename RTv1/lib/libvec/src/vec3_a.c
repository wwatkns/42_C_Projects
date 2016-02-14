/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 10:47:42 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/14 12:36:31 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	v;

	v = (t_vec3) { x, y, z };
	return (v);
}

t_vec3i	vec3i(t_vec3 v)
{
	t_vec3i vi;

	vi = (t_vec3i) { (int)v.x, (int)v.y, (int)v.z };
	return (vi);
}

t_vec3	vec3_scale(t_vec3 v, double scale)
{
	vec3_normalize(&v);
	v.x *= scale;
	v.y *= scale;
	v.z *= scale;
	return (v);
}

double	vec3_magnitude(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

void	vec3_normalize(t_vec3 *v)
{
	double	magnitude;

	magnitude = vec3_magnitude(*v);
	v->x /= magnitude;
	v->y /= magnitude;
	v->z /= magnitude;
}
