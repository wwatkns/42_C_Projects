/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 14:14:23 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/19 14:27:06 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_vec_rotate(t_vec2 *vec2, float theta)
{
	float	t_x;
	float	t_y;

	t_x = vec2->x * cos(theta) - vec2->y * sin(theta);
	t_y = vec2->x * sin(theta) + vec2->y * cos(theta);
	vec2->x = t_x;
	vec2->y = t_y;
}

t_vec2	ft_vec_add(t_vec2 vec2a, t_vec2 vec2b)
{
	t_vec2	vec2;

	vec2.x = vec2a.x + vec2b.x;
	vec2.y = vec2a.y + vec2b.y;
	return (vec2);
}
