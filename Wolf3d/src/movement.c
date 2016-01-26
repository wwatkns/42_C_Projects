/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:10:46 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/26 16:20:16 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	camera_move(t_env *e)
{
	t_vec2	tmp;

	e->cam.vy = (e->key.shift == 1 ? VELY * 1.7 : VELY);
	tmp = e->map.pos;
	if (e->key.w)
		tmp = vec2_add(e->map.pos, vec2_scale(e->cam.dir, e->cam.vy));
	if (e->key.s)
		tmp = vec2_sub(e->map.pos, vec2_scale(e->cam.dir, e->cam.vy));
	e->map.pos = e->map.map[(int)tmp.y][(int)tmp.x] == 0 ? tmp : e->map.pos;
	if (e->key.a)
		tmp = vec2_sub(e->map.pos, vec2_scale(e->cam.pln, e->cam.vx));
	if (e->key.d)
		tmp = vec2_add(e->map.pos, vec2_scale(e->cam.pln, e->cam.vx));
	e->map.pos = e->map.map[(int)tmp.y][(int)tmp.x] == 0 ? tmp : e->map.pos;
}

void	camera_rotate(t_env *e)
{
	e->key.q ? vec2_rotate(&e->cam.dir, -e->cam.vr) : 0;
	e->key.q ? vec2_rotate(&e->cam.pln, -e->cam.vr) : 0;
	e->key.e ? vec2_rotate(&e->cam.dir, e->cam.vr) : 0;
	e->key.e ? vec2_rotate(&e->cam.pln, e->cam.vr) : 0;
}
