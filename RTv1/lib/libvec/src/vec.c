/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:11:57 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/14 12:35:52 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	vec3_up(void)
{
	t_vec3	v;

	v = (t_vec3) { 0, 1, 0 };
	return (v);
}

t_vec3	vec3_right(void)
{
	t_vec3	v;

	v = (t_vec3) { 1, 0, 0 };
	return (v);
}

t_vec3	vec3_forward(void)
{
	t_vec3	v;

	v = (t_vec3) { 0, 0, 1 };
	return (v);
}

t_vec3	vec3_fmul(t_vec3 v, double m)
{
	t_vec3	r;

	r.x = v.x * m;
	r.y = v.y * m;
	r.z = v.z * m;
	return (r);
}

t_vec2	vec2_fmul(t_vec2 v, double m)
{
	t_vec2	r;

	r.x = v.x * m;
	r.y = v.y * m;
	return (r);
}
