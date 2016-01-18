/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:55:09 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/18 12:17:47 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_core(t_env *e)
{
	ft_initenv(e);
	ft_error((int)(e->mlx = mlx_init()));
	ft_error((int)(e->win = mlx_new_window(e->mlx, e->win_w, e->win_h,
	"wolf3d")));
	ft_initimg(e);
//	ft_initfract(e);
//	ft_displayfract(e);
	mlx_hook(e->win, 2, (1L << 0), ft_key_pressed, e);
	mlx_hook(e->win, 3, (1L << 1), ft_key_released, e);
//	mlx_hook(e->win, 6, (1L << 6), ft_mouse_pos, e);
//	mlx_mouse_hook(e->win, ft_mouse_hook, e);
	mlx_expose_hook(e->win, ft_expose_hook, e);
	mlx_loop_hook(e->mlx, ft_loop_hook, e);
	mlx_loop(e->mlx);
}

void	ft_initenv(t_env *e)
{
	e->win_w = e->arg.w;
	e->win_h = e->arg.h;
}
