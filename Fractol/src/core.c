/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 09:35:22 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/11 10:38:08 by wwatkins         ###   ########.fr       */
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
	mlx_expose_hook(e->win, ft_expose_hook, e);
	mlx_loop_hook(e->mlx, ft_loop_hook, e);
	mlx_loop(e->mlx);
}

void	ft_initenv(t_env *e)
{
	e->win_w = e->arg.w;
	e->win_h = e->arg.h;
}
