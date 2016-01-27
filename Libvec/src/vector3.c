/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 10:47:42 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/27 16:27:41 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	vec3(float x, float y, float z)
{
	t_vec3	vec3;

	vec3 = (t_vec3) { x, y, z };
	return (vec3);
}

t_vec3i	vec3i(t_vec3 vec3)
{
	t_vec3i vec3i;

	vec3i = (t_vec3i) { (int)vec3.x, (int)vec3.y, (int)vec3.z };
	return (vec3i);
}

t_vec3	vec3_scale(t_vec3 vec3, float scale)
{
	vec3_normalize(&vec3);
	vec3.x *= scale;
	vec3.y *= scale;
	vec3.z *= scale;
	return (vec3);
}

float	vec3_magnitude(t_vec3 vec3)
{
	return (sqrt(vec3.x * vec3.x + vec3.y * vec3.y + vec3.z * vec3.z));
}

void	vec3_normalize(t_vec3 *vec3)
{
	float	magnitude;

	magnitude = vec3_magnitude(*vec3);
	vec3->x /= magnitude;
	vec3->y /= magnitude;
	vec3->z /= magnitude;
}
