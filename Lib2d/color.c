/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 10:20:12 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/21 15:11:46 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib2d.h"

/*
**	https://github.com/spectrenoir06/FdF42/blob/master/lib2d/color.c
*/

int		ft_rgb2hex(t_color color)
{
	int c;

	c = color.r;
	c = c << 8;
	c += color.g;
	c = c << 8;
	c += color.b;
	return (c);
}

t_color	ft_hex2rgb(int c)
{
	t_color color;

	c = (c & 0x00FFFFFF);
	color.b = (c & 0xFF);
	c = c >> 8;
	color.g = (c & 0xFF);
	c = c >> 8;
	color.r = c;
	return (color);
}

t_color	ft_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

int		ft_rgbcolor(unsigned char r, unsigned char g, unsigned char b)
{
	int c;

	c = r;
	c = c << 8;
	c += g;
	c = c << 8;
	c += b;
	return (c);
}
