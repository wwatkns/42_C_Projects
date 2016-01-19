/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 12:06:26 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/19 14:27:37 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_loop_hook(t_env *e)
{
	if (e->key.a)
	{
		ft_vec_rotate(&e->cam.dir, 0.1);
		ft_vec_rotate(&e->cam.pln, 0.1);
	}
	if (e->key.d)
	{
		ft_vec_rotate(&e->cam.dir, -0.1);
		ft_vec_rotate(&e->cam.pln, -0.1);
	}
	ft_expose_hook(e);
	return (0);
}

int		ft_expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->img.adr);
	ft_initimg(e);
// up
	ft_drawline(e, ft_setvec2(e->cam.pos.x, e->cam.pos.y),
	ft_setvec2(e->cam.pos.x + e->cam.dir.x, e->cam.pos.y + e->cam.dir.y));
// right
	ft_drawline(e, ft_setvec2(e->cam.pos.x + e->cam.dir.x + e->cam.pln.x,
	e->cam.pos.y + e->cam.dir.y + e->cam.pln.y),
	ft_setvec2(e->cam.pos.x + e->cam.dir.x,
	e->cam.pos.y + e->cam.dir.y));
// left
	ft_drawline(e, ft_setvec2(e->cam.pos.x + e->cam.dir.x - e->cam.pln.x,
	e->cam.pos.y + e->cam.dir.y - e->cam.pln.y),
	ft_setvec2(e->cam.pos.x + e->cam.dir.x,
	e->cam.pos.y + e->cam.dir.y));

	mlx_put_image_to_window(e->mlx, e->win, e->img.adr, 0, 0);
	return (0);
}

int		ft_key_pressed(int keycode, t_env *e)
{
	keycode == 53 ? exit(0) : 0;
	keycode == 13 || keycode == 126 ? e->key.w = 1 : 0;
	keycode == 1 || keycode == 125 ? e->key.s = 1 : 0;
	keycode == 0 || keycode == 123 ? e->key.a = 1 : 0;
	keycode == 2 || keycode == 124 ? e->key.d = 1 : 0;
	return (0);
}

int		ft_key_released(int keycode, t_env *e)
{
	keycode == 13 || keycode == 126 ? e->key.w = 0 : 0;
	keycode == 1 || keycode == 125 ? e->key.s = 0 : 0;
	keycode == 0 || keycode == 123 ? e->key.a = 0 : 0;
	keycode == 2 || keycode == 124 ? e->key.d = 0 : 0;
	return (0);
}
