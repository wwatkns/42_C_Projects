/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:46:57 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/20 16:49:51 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
/*
void	raycast(t_env *e)
{
	int		i;
	int		j;
	int		hit;
	t_vec2	ray;
	t_vec2i	ray_t;
	t_vec2i	pos;
	float	angle;

	i = -1;
	angle = e->cam.fov / e->win_w;
	ray = vec2_sub(e->cam.dir, e->cam.pln);
	pos = vec2i(vec2_mul(e->cam.pos,
	vec2((1 / (float)e->win_w * 15), (1 / (float)e->win_w * 15))));
	pos = vec2i(vec2_sub(vec2(pos.x, pos.y), vec2(1, 1)));
	printf("(%d, %d)\n", pos.x, pos.y);
	vec2_normalize(&ray);
	while (++i < e->win_w)
	{
		vec2_rotate(&ray, angle);
		hit = 0;
		j = 1;
		ray_t = vec2i(ray);
		while (!hit)
		{
			if (e->map.map[pos.y + ray_t.y][pos.x + ray_t.x] > 0)
				hit = 1;
			ray_t = vec2i(vec2_scale(ray, j));
			printf("(%d, %d)\n", ray_t.x, ray_t.y);
			j++;
		}
		printf("hit\n");
		//draw_line(e, vec2i(e->cam.pos), vec2i(vec2_add(e->cam.pos,
		//vec2_scale(ray, 1400))));
	}
}*/

void	raycast(t_env *e)
{
	t_vec2	ray;
	t_vec2	ray_t;
	t_vec2	pos;
	float	angle;
	int		i;
	int		j;

	i = -1;
	angle = e->cam.fov / e->win_w;
	ray = vec2_sub(e->cam.dir, e->cam.pln);
	vec2_normalize(&ray);
	pos = vec2_mul(e->cam.pos, vec2(15 / (float)e->win_w, 15 / (float)e->win_w));
	pos = (t_vec2) { (int)pos.x, (int)pos.y };
//	printf("r: (%f, %f) - p: (%f, %f)\n", ray.x, ray.y, pos.x, pos.y);
	while (++i < e->win_w)
	{
		vec2_rotate(&ray, angle);
		j = 1;
		ray_t = ray;
		while (1)
		{
			if (pos.x + ray_t.x < 0 || pos.y + ray_t.y < 0 ||
				pos.x + ray_t.x > e->map.w - 1 ||
				pos.y + ray_t.y > e->map.w - 1)
				break ;
			if (e->map.map[(int)(pos.y + ray_t.y)][(int)(pos.x + ray_t.x)] > 0)
				break ;
			ray_t = vec2_scale(ray_t, j);
			//printf("(%f, %f)\n", ray_t.x, ray_t.y);
			j++;
		}
		draw_line(e, vec2i(e->cam.pos),
		vec2i(vec2_add(e->cam.pos, vec2_scale(ray_t, 500))));
		//printf("Hit\n");
	}
}




