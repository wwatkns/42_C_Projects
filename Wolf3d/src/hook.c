/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 12:06:26 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/27 12:49:50 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		loop_hook(t_env *e)
{
	camera_move(e);
	camera_rotate(e);
	e->key.m ? mouse_look_free(e) : mouse_look(e);
	expose_hook(e);
	return (0);
}

int		expose_hook(t_env *e)
{
	if (e->tex.f == -1 || e->tex.c == -1)
	{
		mlx_destroy_image(e->mlx, e->img.adr);
		img_init(e);
	}
	raycast(e);
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img.adr, 0, 0);
	return (0);
}

int		key_pressed(int keycode, t_env *e)
{
	keycode == 53 ? exit(0) : 0;
	keycode == 13 || keycode == 126 ? e->key.w = 1 : 0;
	keycode == 1 || keycode == 125 ? e->key.s = 1 : 0;
	keycode == 0 || keycode == 123 ? e->key.a = 1 : 0;
	keycode == 2 || keycode == 124 ? e->key.d = 1 : 0;
	keycode == 12 ? e->key.q = 1 : 0;
	keycode == 14 ? e->key.e = 1 : 0;
	keycode == 46 ? key_switch(&e->key.m) : 0;
	keycode == 257 || keycode == 258 ? e->key.shift = 1 : 0;
	return (0);
}

int		key_released(int keycode, t_env *e)
{
	keycode == 13 || keycode == 126 ? e->key.w = 0 : 0;
	keycode == 1 || keycode == 125 ? e->key.s = 0 : 0;
	keycode == 0 || keycode == 123 ? e->key.a = 0 : 0;
	keycode == 2 || keycode == 124 ? e->key.d = 0 : 0;
	keycode == 12 ? e->key.q = 0 : 0;
	keycode == 14 ? e->key.e = 0 : 0;
	keycode == 257 || keycode == 258 ? e->key.shift = 0 : 0;
	return (0);
}

void	key_switch(short *key)
{
	int t;

	t = 0;
	*key == 1 ? t = 1 : 0;
	*key == 1 ? *key = 0 : 0;
	*key == 0 && t != 1 ? *key = 1 : 0;
}
