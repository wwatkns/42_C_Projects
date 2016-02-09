/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 10:57:57 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/09 08:09:21 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec2	vec2_add(t_vec2 vec2a, t_vec2 vec2b)
{
	t_vec2	vec2;

	vec2.x = vec2a.x + vec2b.x;
	vec2.y = vec2a.y + vec2b.y;
	return (vec2);
}

t_vec2	vec2_sub(t_vec2 vec2a, t_vec2 vec2b)
{
	t_vec2	vec2;

	vec2.x = vec2a.x - vec2b.x;
	vec2.y = vec2a.y - vec2b.y;
	return (vec2);
}

t_vec2	vec2_mul(t_vec2 vec2a, t_vec2 vec2b)
{
	t_vec2	vec2;

	vec2.x = vec2a.x * vec2b.x;
	vec2.y = vec2a.y * vec2b.y;
	return (vec2);
}

double	vec2_dot(t_vec2 vec2a, t_vec2 vec2b)
{
	return ((vec2a.x * vec2b.x + vec2a.y * vec2b.y));
}

void	vec2_rot(t_vec2 *vec2, double theta)
{
	t_vec2	vec2t;

	theta *= DEG2RAD;
	vec2t.x = vec2->x * cos(theta) - vec2->y * sin(theta);
	vec2t.y = vec2->x * sin(theta) + vec2->y * cos(theta);
	vec2->x = vec2t.x;
	vec2->y = vec2t.y;
}
