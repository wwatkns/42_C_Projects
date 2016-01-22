/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:10:46 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/22 17:30:29 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	camera_move(t_env *e)
{
	e->cam.vy = (e->key.shift == 1 ? 0.1 : 0.058);
	if (e->key.w && !camera_collision(e))
		e->map.pos = vec2_add(e->map.pos, vec2_scale(e->cam.dir, e->cam.vy));
	if (e->key.s && !camera_collision(e))
		e->map.pos = vec2_sub(e->map.pos, vec2_scale(e->cam.dir, e->cam.vy));
	if (e->key.a && !camera_collision(e))
		e->map.pos = vec2_sub(e->map.pos, vec2_scale(e->cam.pln, e->cam.vx));
	if (e->key.d && !camera_collision(e))
		e->map.pos = vec2_add(e->map.pos, vec2_scale(e->cam.pln, e->cam.vx));
}

void	camera_rotate(t_env *e)
{
	e->key.q ? vec2_rotate(&e->cam.dir, -e->cam.vr) : 0;
	e->key.q ? vec2_rotate(&e->cam.pln, -e->cam.vr) : 0;
	e->key.e ? vec2_rotate(&e->cam.dir, e->cam.vr) : 0;
	e->key.e ? vec2_rotate(&e->cam.pln, e->cam.vr) : 0;
}

int		camera_collision(t_env *e)
{
	t_vec2	next;

	if (e->key.w)
		next = vec2_add(e->map.pos, vec2_scale(e->cam.dir, e->cam.vy));
	if (e->key.s)
		next = vec2_sub(e->map.pos, vec2_scale(e->cam.dir, e->cam.vy));
	if (e->key.a)
		next = vec2_sub(e->map.pos, vec2_scale(e->cam.pln, e->cam.vy));
	if (e->key.d)
		next = vec2_add(e->map.pos, vec2_scale(e->cam.pln, e->cam.vy));
	return (e->map.map[(int)next.x][(int)next.y]);
}
