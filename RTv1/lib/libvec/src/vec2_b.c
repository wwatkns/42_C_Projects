/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 10:57:57 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/14 12:36:15 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec2	vec2_add(t_vec2 va, t_vec2 vb)
{
	t_vec2	v;

	v.x = va.x + vb.x;
	v.y = va.y + vb.y;
	return (v);
}

t_vec2	vec2_sub(t_vec2 va, t_vec2 vb)
{
	t_vec2	v;

	v.x = va.x - vb.x;
	v.y = va.y - vb.y;
	return (v);
}

t_vec2	vec2_mul(t_vec2 va, t_vec2 vb)
{
	t_vec2	v;

	v.x = va.x * vb.x;
	v.y = va.y * vb.y;
	return (v);
}

double	vec2_dot(t_vec2 va, t_vec2 vb)
{
	return ((va.x * vb.x + va.y * vb.y));
}

void	vec2_rot(t_vec2 *v, double theta)
{
	t_vec2	r;

	theta *= DEG2RAD;
	r.x = v->x * cos(theta) - v->y * sin(theta);
	r.y = v->x * sin(theta) + v->y * cos(theta);
	*v = r;
}
