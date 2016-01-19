/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 14:14:23 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/19 15:40:24 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	vec2_rot(t_vec2 *vec2, float theta)
{
	float	t_x;
	float	t_y;

	t_x = vec2->x * cos(theta) - vec2->y * sin(theta);
	t_y = vec2->x * sin(theta) + vec2->y * cos(theta);
	vec2->x = t_x;
	vec2->y = t_y;
}

t_vec2	vec2_add(t_vec2 vec2a, t_vec2 vec2b)
{
	t_vec2	vec2;

	vec2.x = vec2a.x + vec2b.x;
	vec2.y = vec2a.y + vec2b.y;
	return (vec2);
}

float	vec2_magnitude(t_vec2 vec2)
{
	return (sqrt(vec2.x * vec2.x + vec2.y * vec2.y));
}

void	vec2_normalize(t_vec2 *vec2)
{
	float	magnitude;

	magnitude = vec2_magnitude(*vec2);
	vec2->x /= magnitude;
	vec2->y /= magnitude;
}

t_vec2	vec2_mul(t_vec2 vec2a, t_vec2 vec2b)
{
	t_vec2	vec2;

	vec2.x = vec2a.x * vec2b.x;
	vec2.y = vec2a.y * vec2b.y;
	return (vec2);
}

t_vec2	vec2f(float x, float y)
{
	t_vec2  vector;

	vector = (t_vec2) { x, y };
	return (vector);
}

t_vec2	vec2(int x, int y)
{
	t_vec2  vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}
