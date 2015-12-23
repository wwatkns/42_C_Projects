/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 11:54:21 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/23 12:24:53 by wwatkins         ###   ########.fr       */
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
	e->move.y = 0;
	e->move.x = 0;
	e->zoom = 1;
	e->move.y = (-e->key.u + e->key.d) * 2;
	e->move.x = (-e->key.l + e->key.r) * 2;
	e->zoom = 1 + e->key.zp;
	ft_displaylines(e);
	return (1);
}

int		ft_exposehook(t_env *e)
{
	ft_displaylines(e);
	return (1);
}
