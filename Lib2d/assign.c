/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:06:51 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/21 14:06:53 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib2d.h"

t_point		ft_point(int x, int y)
{
	t_point point;

	point.x = x;
	point.y = y;
	return (point);
}

t_line		ft_line(int x, int y, int x1, int y1)
{
	t_line line;

	line.p0.x = x;
	line.p0.y = y;
	line.p1.x = x1;
	line.p1.y = y1;
	line.dx = 0;
	line.dy = 0;
	return (line);
}

t_rect		ft_rect(int x, int y, int x1, int y1)
{
	t_rect rect;

	rect.p0.x = x;
	rect.p0.y = y;
	rect.p1.x = x1;
	rect.p1.y = y1;
	return (rect);
}

t_circle	ft_circle(int x, int y, int r)
{
	t_circle circle;

	circle.p.x = x;
	circle.p.y = y;
	circle.r = r;
	return (circle);
}
