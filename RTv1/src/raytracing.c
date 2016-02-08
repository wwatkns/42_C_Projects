/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 11:03:23 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/08 15:29:35 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	raytracing(t_env *e)
{
	e->ray.y = 0;
	while (e->ray.y < e->win.h)
	{
		e->ray.x = 0;
		while (e->ray.x < e->win.w)
		{
			raytracing_init(e);
			raytracing_calc(e);
//			raytracing_draw(e);
			e->ray.x++;
		}
		e->ray.y++;
	}
}

void	raytracing_init(t_env *e)
{
	e->ray.pos = e->cam.pos;
	e->ray.dir = e->cam.origin;
	e->ray.len = vec3(0, 0, 0);
	e->ray.dist = 0;
	e->ray.dir = vec3_add(e->cam.origin, vec3_sub(
				vec3_fmul(vec3_right(), e->cam.xi * e->ray.x),
				vec3_fmul(vec3_up(), e->cam.yi * e->ray.y)));
	vec3_normalize(&e->ray.dir);
}

void	raytracing_calc(t_env *e)
{
	t_obj	*current;

	current = e->obj->next;
	while (current != NULL)
	{
		current->type == CONE ? ray_intersect_cone(e) : 0;
		current->type == PLANE ? ray_intersect_plane(e) : 0;
		current->type == SPHERE ? ray_intersect_sphere(e) : 0;
		current->type == CYLINDER ? ray_intersect_cylinder(e) : 0;
		current = current->next;
	}
}
/*
void	raytracing_draw(t_env *e)
{
}*/
