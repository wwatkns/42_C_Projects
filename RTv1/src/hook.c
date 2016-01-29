/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 12:57:27 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/29 13:59:58 by wwatkins         ###   ########.fr       */
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
	mlx_clear_window(e->mlx, e->win.adr);
	mlx_put_image_to_window(e->mlx, e->win.adr, e->img.adr, 0, 0);
	return (0);
}

int		key_pressed(int keycode, t_env *e)
{
	keycode == 53 ? exit(0) : 0;
	e->win.h > 5000 ? exit(0) : 0; // suppress compilation warning
	return (0);
}
