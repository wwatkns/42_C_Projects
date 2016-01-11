/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:03:22 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/11 10:25:10 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_loop_hook(t_env *e)
{
	ft_expose_hook(e);
	return (0);
}

int		ft_expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img.adr, 0, 0);
	return (0);
}
