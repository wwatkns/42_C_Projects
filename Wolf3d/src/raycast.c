/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:46:57 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/20 14:39:11 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	raycast(t_env *e)
{
	int		i;
	t_vec2	ray;
	float	angle;

	i = -1;
	angle = e->cam.fov / e->win_w;
	ray = vec2_sub(e->cam.dir, e->cam.pln);
	vec2_normalize(&ray);
	while (++i < e->win_w)
	{
		vec2_rotate(&ray, angle);
		//draw_line(e, vec2i(e->cam.pos), vec2i(vec2_add(e->cam.pos,
		//vec2_scale(ray, 1400))));
	}
}
