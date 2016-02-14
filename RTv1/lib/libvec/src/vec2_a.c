/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:23:31 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/14 12:30:26 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec2	vec2(double x, double y)
{
	t_vec2	v;

	v = (t_vec2) { x, y };
	return (v);
}

t_vec2i	vec2i(t_vec2 v)
{
	t_vec2i vi;

	vi = (t_vec2i) { (int)v.x, (int)v.y };
	return (vi);
}

t_vec2	vec2_scale(t_vec2 v, double scale)
{
	vec2_normalize(&v);
	v.x *= scale;
	v.y *= scale;
	return (v);
}

double	vec2_magnitude(t_vec2 v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}

void	vec2_normalize(t_vec2 *v)
{
	double	magnitude;

	magnitude = vec2_magnitude(*v);
	v->x /= magnitude;
	v->y /= magnitude;
}
