/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 12:57:27 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/10 18:04:31 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		loop_hook(t_env *e)
{
	expose_hook(e);
	return (0);
}

int		expose_hook(t_env *e)
{
	raytracing(e);
	mlx_clear_window(e->mlx, e->win.adr);
	mlx_put_image_to_window(e->mlx, e->win.adr, e->img.adr, 0, 0);
	return (0);
}

int		key_pressed(int keycode, t_env *e)
{
	keycode == 53 ? exit(0) : 0;
	keycode == 126 ? e->key.u = 1 : 0;
	keycode == 125 ? e->key.d = 1 : 0;
	keycode == 123 ? e->key.l = 1 : 0;
	keycode == 124 ? e->key.r = 1 : 0;
	return (0);
}

int		key_released(int keycode, t_env *e)
{
	keycode == 53 ? exit(0) : 0;
	keycode == 126 ? e->key.u = 0 : 0;
	keycode == 125 ? e->key.d = 0 : 0;
	keycode == 123 ? e->key.l = 0 : 0;
	keycode == 124 ? e->key.r = 0 : 0;
	return (0);
}
