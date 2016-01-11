/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 13:35:13 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/11 09:17:35 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawhorizontal(t_env *e, t_point p, t_point p1)
{
	while (p.x < p1.x)
	{
		ft_imgpixelput(e, p.x, p.y, ft_getcolor(e, p));
		p.x++;
	}
}

void	ft_drawtriangle(t_env *e, t_point p, t_point p1, t_point p2)
{
	while (p.y < p2.y)
	{
		e->cam.mode == 2 ? ft_drawline(e, p, p1) : 0;
		e->cam.mode == 3 ? ft_drawhorizontal(e, p, p1) : 0;
		p.y++;
	}
}
