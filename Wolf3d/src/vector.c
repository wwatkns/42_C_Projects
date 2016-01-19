/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 14:14:23 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/19 15:55:37 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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

void	vec2_scale(t_vec2 *vec2, float scale)
{
	vec2_normalize(vec2);
	vec2->x *= scale;
	vec2->y *= scale;
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
