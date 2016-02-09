/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:11:57 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/09 08:08:22 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	vec3_up(void)
{
	t_vec3	vec3;

	vec3 = (t_vec3) {0.0, 1.0, 0.0};
	return (vec3);
}

t_vec3	vec3_right(void)
{
	t_vec3	vec3;

	vec3 = (t_vec3) {1.0, 0.0, 0.0};
	return (vec3);
}

t_vec3	vec3_forward(void)
{
	t_vec3	vec3;

	vec3 = (t_vec3) {0.0, 0.0, 1.0};
	return (vec3);
}

t_vec3	vec3_fmul(t_vec3 vec3, double m)
{
	t_vec3	vec3t;

	vec3t.x = vec3.x * m;
	vec3t.y = vec3.y * m;
	vec3t.z = vec3.z * m;
	return (vec3t);
}

t_vec2	vec2_fmul(t_vec2 vec2, double m)
{
	t_vec2	vec2t;

	vec2t.x = vec2.x * m;
	vec2t.y = vec2.y * m;
	return (vec2t);
}
