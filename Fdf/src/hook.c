/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 11:54:21 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/04 12:00:48 by wwatkins         ###   ########.fr       */
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
	keycode == 35 ? e->key.p = 1 : 0;
	printf("%d\n", keycode);
	return (1);
}

int		ft_keyhook_release(int keycode, t_env *e)
{
	keycode == 126 ? e->key.w = 0 : 0;
	keycode == 125 ? e->key.s = 0 : 0;
	keycode == 123 ? e->key.a = 0 : 0;
	keycode == 124 ? e->key.d = 0 : 0;
	keycode == 35 ? e->key.p = 0 : 0;
	return (1);
}

int		ft_loophook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->img.adr);
	e->cam.move.y = 0;
	e->cam.move.x = 0;
	e->cam.move.y = (-e->key.s + e->key.w) * 4;
	e->cam.move.x = (-e->key.d + e->key.a) * 4;
	e->key.p == 1 ? ft_setpalette(e, e->palette.i) : 0;
	ft_exposehook(e);
	return (1);
}

int		ft_exposehook(t_env *e)
{
	ft_initimg(e);
	ft_displaylines(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.adr, 0, 0);
	ft_debugmessage(e);
	return (1);
}

int		ft_debugmessage(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 2, 0xFFFFBF, "arrows: move camera.");
	mlx_string_put(e->mlx, e->win, 10, 17, 0xFFFFBF, "     p: change palette.");
	return (1);
}