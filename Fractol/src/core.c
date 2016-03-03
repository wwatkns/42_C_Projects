/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 09:35:22 by wwatkins          #+#    #+#             */
/*   Updated: 2016/03/03 12:51:27 by wwatkins         ###   ########.fr       */
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
	mlx_mouse_hook(e->win, ft_mouse_hook, e);
	mlx_expose_hook(e->win, ft_expose_hook, e);
	mlx_loop_hook(e->mlx, ft_loop_hook, e);
	mlx_loop(e->mlx);
}

void	ft_displayfract(t_env *e)
{
	int	t;

	t = 0;
	while (t < THREADS_NUM)
	{
		e->thread_id = t;
		pthread_create(&e->threads[t], NULL, (void*)ft_displayfract_thread, e);
		pthread_join(e->threads[t], NULL);
		t++;
	}
}

void	ft_displayfract_thread(t_env *e)
{
	int	x;
	int	y;

	y = e->thread_id;
	e->f.zwin_w = e->f.zoom * e->win_w;
	e->f.zwin_h = e->f.zoom * e->win_h;
	while (y < e->win_h)
	{
		x = -1;
		while (++x < e->win_w)
		{
			e->f.n == 0 ? ft_mandelbrot(e, x, y) : 0;
			e->f.n == 1 ? ft_julia(e, x, y) : 0;
			e->f.n == 2 ? ft_burningship(e, x, y) : 0;
			e->f.n == 3 ? ft_tricorn(e, x, y) : 0;
		}
		y += THREADS_NUM;
	}
//	pthread_exit(NULL);
}

void	ft_initenv(t_env *e)
{
	e->win_w = e->arg.w;
	e->win_h = e->arg.h;
	e->hwin_w = e->arg.w / 2.0;
	e->hwin_h = e->arg.h / 2.0;
	e->key.p = 0;
	e->key.pu = 0;
	e->key.pd = 0;
	e->key.kp = 0;
	e->key.km = 0;
	e->mouse.x = e->hwin_w;
	e->mouse.y = e->hwin_h;
	e->threads = (pthread_t*)malloc(sizeof(pthread_t) * THREADS_NUM);
}
