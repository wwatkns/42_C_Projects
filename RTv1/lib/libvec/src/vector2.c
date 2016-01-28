/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:23:31 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/27 16:27:08 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec2	vec2(float x, float y)
{
	t_vec2	vec2;

	vec2 = (t_vec2) { x, y };
	return (vec2);
}

t_vec2i	vec2i(t_vec2 vec2)
{
	t_vec2i vec2i;

	vec2i = (t_vec2i) { (int)vec2.x, (int)vec2.y };
	return (vec2i);
}

t_vec2	vec2_scale(t_vec2 vec2, float scale)
{
	vec2_normalize(&vec2);
	vec2.x *= scale;
	vec2.y *= scale;
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
