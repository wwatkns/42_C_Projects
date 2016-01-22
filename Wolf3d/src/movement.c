/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:10:46 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/22 16:15:17 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	camera_move(t_env *e)
{
	e->cam.vy = (e->key.shift == 1 ? 0.1 : 0.058);
	if (e->key.w)
		e->map.pos = vec2_add(e->map.pos, vec2_scale(e->cam.dir, e->cam.vy));
	if (e->key.s)
		e->map.pos = vec2_sub(e->map.pos, vec2_scale(e->cam.dir, e->cam.vy));
	if (e->key.a)
		e->map.pos = vec2_sub(e->map.pos, vec2_scale(e->cam.pln, e->cam.vx));
	if (e->key.d)
		e->map.pos = vec2_add(e->map.pos, vec2_scale(e->cam.pln, e->cam.vx));
}

void	camera_rotate(t_env *e)
{
	e->key.q ? vec2_rotate(&e->cam.dir, -e->cam.vr) : 0;
	e->key.q ? vec2_rotate(&e->cam.pln, -e->cam.vr) : 0;
	e->key.e ? vec2_rotate(&e->cam.dir, e->cam.vr) : 0;
	e->key.e ? vec2_rotate(&e->cam.pln, e->cam.vr) : 0;
}

/*float get_velocity(t_env *e)
{
	float           vel = 0;
	static float    acc = 0;
	static int      dec = 0;

	vel = VEL * acc;
	acc += 0.075;
	if (dec && !e->key.w && acc > 0)
	acc = 0;
	acc > 1 ? acc = 1 : 0;
	acc < 0 ? acc = 0 : 0;

	if (dec && acc == 0)
	dec = 0;
	else if (!dec && acc > 0)
	dec = e->key.w;

	return(vel);
}*/
