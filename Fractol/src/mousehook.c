/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 13:15:01 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/12 15:32:28 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse_pos(int x, int y, t_env *e)
{
	e->mouse.x = x;
	e->mouse.y = y;
	return (0);
}

int		ft_mouse_hook(int button, int x, int y, t_env *e)
{
	button == 4 ? e->f.zoom *= 1.05f : 0;
	button == 5 ? e->f.zoom *= 0.95f : 0;
	button == 4 ? e->mouse.zp = 1 : 0;
	button == 5 ? e->mouse.zm = 1 : 0;
	e->mouse.x = x;
	e->mouse.y = y;
	return (0);
}
