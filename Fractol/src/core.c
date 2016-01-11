/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 09:35:22 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/11 14:58:06 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_core(t_env *e)
{
	ft_initenv(e);
	ft_error((int)(e->mlx = mlx_init()));
	ft_error((int)(e->win = mlx_new_window(e->mlx, e->win_w, e->win_h,
	e->arg.fract)));
	ft_initimg(e);
	ft_initfract(e);
	ft_displayfract(e);
	mlx_hook(e->win, 2, (1L << 0), ft_key_pressed, e);
	mlx_hook(e->win, 3, (1L << 1), ft_key_released, e);
	mlx_hook(e->win, 6, (1L << 6), ft_mouse_pos, e);
	mlx_expose_hook(e->win, ft_expose_hook, e);
	mlx_loop_hook(e->mlx, ft_loop_hook, e);
	mlx_loop(e->mlx);
}

void	ft_displayfract(t_env *e)
{
	int	x;
	int	y;

	y = 0;
	while (y < e->win_h)
	{
		x = 0;
		while (x < e->win_w)
		{
			!ft_strcmp(e->arg.fract, "mandelbrot") ? ft_mandelbrot(e, x, y) : 0;
			//!ft_strcmp(e->arg.fract, "julia") ? ft_julia(e, x, y) : 0;
			x++;
		}
		y++;
	}
}

void	ft_initenv(t_env *e)
{
	e->win_w = e->arg.w;
	e->win_h = e->arg.h;
	e->key.w = 0;
	e->key.s = 0;
	e->key.a = 0;
	e->key.d = 0;
	e->key.kp = 0;
	e->key.km = 0;
	e->mouse.x = e->win_w / 2.0f;
	e->mouse.y = e->win_h / 2.0f;
}
