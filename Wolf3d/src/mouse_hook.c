/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 13:17:20 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/22 14:34:32 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		mouse_pos(int x, int y, t_env *e)
{
	e->mouse.x = x;
	e->mouse.y = y;
	return (0);
}

void	mouse_rotate_dif(t_env *e)
{
	float	angle;
	float	dif;

	dif = e->mouse.x - (e->win_w / 2);
	angle = dif / 100;
	vec2_rotate(&e->cam.dir, angle);
	vec2_rotate(&e->cam.pln, angle);
}

void	mouse_rotate(t_env *e)
{
	float			angle;
	float			dif;
	static float	old = 0;

	dif = e->mouse.x - old;
	old = e->mouse.x;
	angle = PIOVER4 * 0.5 * dif;
	vec2_rotate(&e->cam.dir, angle);
	vec2_rotate(&e->cam.pln, angle);
}
