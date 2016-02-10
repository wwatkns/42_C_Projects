/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 18:31:06 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/10 15:22:28 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

void	vec3_clamp(t_vec3 *vec3, double min, double max)
{
	vec3->x > max ? vec3->x = max : 0;
	vec3->y > max ? vec3->y = max : 0;
	vec3->z > max ? vec3->z = max : 0;
	vec3->x < min ? vec3->x = min : 0;
	vec3->y < min ? vec3->y = min : 0;
	vec3->z < min ? vec3->z = min : 0;
}

t_vec3	vec3_cross(t_vec3 vec3a, t_vec3 vec3b)
{
	t_vec3	vec3;

	vec3.x = vec3a.y * vec3b.z - vec3a.z * vec3b.y;
	vec3.y = vec3a.z * vec3b.x - vec3a.x * vec3b.z;
	vec3.z = vec3a.x * vec3b.y - vec3a.y * vec3b.x;
	return (vec3);
}

t_vec3	vec3_reflect(t_vec3 d, t_vec3 n)
{
	return (vec3_sub(d, vec3_fmul(n, 2.0 * vec3_dot(d, n))));
}
