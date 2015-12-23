/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 11:54:21 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/23 19:45:25 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_keyhook_pressed(int keycode, t_env *e)
{
	keycode == 53 ? exit(0) : 0;
	keycode == 126 ? e->key.u = 1 : 0;
	keycode == 125 ? e->key.d = 1 : 0;
	keycode == 123 ? e->key.l = 1 : 0;
	keycode == 124 ? e->key.r = 1 : 0;
	keycode == 69 ? e->key.zp = 1 : 0;
	keycode == 78 ? e->key.zm = 1 : 0;
	printf("%d\n", keycode);
	return (1);
}

int		ft_keyhook_release(int keycode, t_env *e)
{
	keycode == 126 ? e->key.u = 0 : 0;
	keycode == 125 ? e->key.d = 0 : 0;
	keycode == 123 ? e->key.l = 0 : 0;
	keycode == 124 ? e->key.r = 0 : 0;
	keycode == 69 ? e->key.zp = 0 : 0;
	keycode == 78 ? e->key.zm = 0 : 0;
	return (1);
}

int		ft_loophook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->cam.move.y = 0;
	e->cam.move.x = 0;
	e->cam.zoom = 1;
	e->cam.move.y = (-e->key.d + e->key.u) * 4;
	e->cam.move.x = (-e->key.r + e->key.l) * 4;
	e->cam.zoom = 1 + e->key.zp;
	ft_exposehook(e);
	return (1);
}

int		ft_exposehook(t_env *e)
{
	ft_displaylines(e);
	ft_debugmessage(e);
	return (1);
}

int		ft_debugmessage(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 2, 0xFFFFBF, "Move camera with arrows.");
	mlx_string_put(e->mlx, e->win, 10, 20, 0xFFFFBF, "Zoom with '+' and '-'.");
	return (1);
}
