/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 15:59:18 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/08 16:03:19 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib2d.h"

void	ft_img_pixel_put(t_env *e, int x, int y, int color)
{
	int pos;

	if (x >= 0 && x < e->winw && y >= 0 < e->winh)
	{
		pos = (x * e->img.bpp / 8) + (y * e->img.sl);
		e->img.img[pos] = color % 256;
		e->img.img[pos + 1] = (color >> 8) % 256;
		e->img.img[pos + 2] = (color >> 16) % 256;
	}
}
