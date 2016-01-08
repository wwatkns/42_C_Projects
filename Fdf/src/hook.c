/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 11:54:21 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/08 10:03:24 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_keyhook_pressed(int keycode, t_env *e)
{
	keycode == 53 ? exit(0) : 0;
	keycode == 126 ? e->key.w = 1 : 0;
	keycode == 125 ? e->key.s = 1 : 0;
	keycode == 123 ? e->key.a = 1 : 0;
	keycode == 124 ? e->key.d = 1 : 0;
	keycode == 34 ? e->key.i = 1 : 0;
	keycode == 40 ? e->key.k = 1 : 0;
	keycode == 35 ? e->key.p = 1 : 0;
	keycode == 69 ? e->key.kp = 1 : 0;
	keycode == 78 ? e->key.km = 1 : 0;
	keycode == 116 ? e->key.pu = 1 : 0;
	keycode == 121 ? e->key.pd = 1 : 0;
	return (0);
}

int		ft_keyhook_release(int keycode, t_env *e)
{
	keycode == 126 ? e->key.w = 0 : 0;
	keycode == 125 ? e->key.s = 0 : 0;
	keycode == 123 ? e->key.a = 0 : 0;
	keycode == 124 ? e->key.d = 0 : 0;
	keycode == 34 ? e->key.i = 0 : 0;
	keycode == 40 ? e->key.k = 0 : 0;
	keycode == 35 ? e->key.p = 0 : 0;
	keycode == 69 ? e->key.kp = 0 : 0;
	keycode == 78 ? e->key.km = 0 : 0;
	keycode == 116 ? e->key.pu = 0 : 0;
	keycode == 121 ? e->key.pd = 0 : 0;
	return (0);
}

int		ft_loophook(t_env *e)
{
	e->cam.x += (e->key.a - e->key.d) * 6;
	e->cam.y += (e->key.w - e->key.s) * 6;
	e->cam.alt += (e->key.i - e->key.k) * 0.1f;
	e->cam.zoom += (e->key.kp - e->key.km);
	e->cam.zoom < 1 ? e->cam.zoom = 1 : 0;
	if (e->key.p)
	{
		ft_setpalette(e);
		ft_displaylines(e);
	}
	e->palette.step += (e->key.pu - e->key.pd);
	ft_exposehook(e);
	return (0);
}

int		ft_exposehook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (e->key.i || e->key.k || e->key.p || e->key.kp || e->key.km ||
		e->key.pu || e->key.pd || e->key.w || e->key.s || e->key.a || e->key.d)
	{
		mlx_destroy_image(e->mlx, e->img.adr);
		ft_initimg(e);
		ft_displaylines(e);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img.adr, 0, 0);
	ft_debugmessage(e);
	return (0);
}

int		ft_debugmessage(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 2, 0xFFFFDF,
			"[pgup, pgdwn]: move color altitude");
	mlx_string_put(e->mlx, e->win, 10, 20, 0xFFFFDF,
			"     [arrows]: move camera");
	mlx_string_put(e->mlx, e->win, 10, 38, 0xFFFFDF,
			"       [i, k]: change altitude");
	mlx_string_put(e->mlx, e->win, 10, 56, 0xFFFFDF,
			"       [+, -]: change zoom");
	mlx_string_put(e->mlx, e->win, 10, 74, 0xFFFFDF,
			"          [p]: change palette");
	return (1);
}
