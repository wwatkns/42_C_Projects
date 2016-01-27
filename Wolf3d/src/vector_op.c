/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:54:33 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/27 10:31:32 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	vec2_rotate(t_vec2 *vec2, float theta)
{
	t_vec2	vec2t;

	theta *= DEG2RAD;
	vec2t.x = vec2->x * cos(theta) - vec2->y * sin(theta);
	vec2t.y = vec2->x * sin(theta) + vec2->y * cos(theta);
	vec2->x = vec2t.x;
	vec2->y = vec2t.y;
}

t_vec2	vec2_add(t_vec2 vec2_a, t_vec2 vec2_b)
{
	t_vec2	vec2;

	vec2.x = vec2_a.x + vec2_b.x;
	vec2.y = vec2_a.y + vec2_b.y;
	return (vec2);
}

t_vec2	vec2_sub(t_vec2 vec2_a, t_vec2 vec2_b)
{
	t_vec2	vec2;

	vec2.x = vec2_a.x - vec2_b.x;
	vec2.y = vec2_a.y - vec2_b.y;
	return (vec2);
}

t_vec2	vec2_mul(t_vec2 vec2_a, t_vec2 vec2_b)
{
	t_vec2	vec2;

	vec2.x = vec2_a.x * vec2_b.x;
	vec2.y = vec2_a.y * vec2_b.y;
	return (vec2);
}

float	vec2_dot(t_vec2 vec2_a, t_vec2 vec2_b)
{
	return ((vec2_a.x * vec2_b.x + vec2_a.y * vec2_b.y));
}
