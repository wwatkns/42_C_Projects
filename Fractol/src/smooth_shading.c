/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_shading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:50:19 by wwatkins          #+#    #+#             */
/*   Updated: 2017/04/15 21:54:06 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		*smooth_shading(t_fract *f, int *iteration, int e)
{
	double	mu;

	f->n == 0 ? reduce_error_mandelbrot(f, iteration, e) : 0;
	f->n == 1 ? reduce_error_julia(f, iteration, e) : 0;
	f->n == 2 ? reduce_error_burningship(f, iteration, e) : 0;
	// e->f.n == 3 ? ft_tricorn(&th->e, x, y) : 0;
	mu = compute_mu(f, *iteration);
	return (get_smooth_color(mu));
}

int		*get_smooth_color(double mu)
{
	static int	rgb[3];
	int 		c[2];
	double		t[2];
	// int 		count = 10;
	// int 		palette[10] = {0xFF0000, 0xffb000, 0xfaff00, 0x00ff5e, 0x00d1ff,
					// 0x3025b8, 0xd839f9, 0xe684b9, 0xfb0d5b, 0x15f482};
	int			count = 8;
	int 		palette[8] = {0xFAF0C8, 0xFAE97D, 0xD76806, 0x9B3411, 0x490528,
					0x110640, 0x0E43B1, 0x83BEDF};

	c[0] = (int)mu;
	t[1] = mu - c[0];
	t[0] = 1 - t[1];
	c[0] = c[0] % count;
	c[1] = (c[0] + 1) % count;

	rgb[0] = (palette[c[0]] & 0xff) * t[0];
	rgb[1] = ((palette[c[0]] >> 8) & 0xff) * t[0];
	rgb[2] = ((palette[c[0]] >> 16) & 0xff) * t[0];
	rgb[0] += (palette[c[1]] & 0xff) * t[1];
	rgb[1] += ((palette[c[1]] >> 8) & 0xff) * t[1];
	rgb[2] += ((palette[c[1]] >> 16) & 0xff) * t[1];

	return (rgb);
}

double	compute_mu(t_fract *f, int iteration)
{
	double  mu;
	double  mag;

	mag = sqrt(f->x2 + f->y2);
	mu = iteration + 1 - log(log(mag)) / log(2.0);
	return (mu / 8);
}

void	reduce_error_mandelbrot(t_fract *f, int *iteration, int e)
{
	int i;

	i = -1;
	while (++i < e)
	{
		f->y = (f->x + f->x) * f->y + f->c_im;
		f->x = f->x2 - f->y2 + f->c_re;
		f->x2 = f->x * f->x;
		f->y2 = f->y * f->y;
		++(*iteration);
	}
}

void	reduce_error_burningship(t_fract *f, int *iteration, int e)
{
	int i;

	i = -1;
	while (++i < e)
	{
		f->y = 2.0 * ABS((f->x * f->y)) + f->c_im;
		f->x = f->x2 - f->y2 - f->c_re;
		f->x2 = f->x * f->x;
		f->y2 = f->y * f->y;
		++(*iteration);
	}
}

void	reduce_error_julia(t_fract *f, int *iteration, int e)
{
	int i;

	i = -1;
	while (++i < e)
	{
		f->y = (f->x + f->x) * f->y + f->c_im;
		f->x = f->x2 - f->y2 + f->c_re;
		f->x2 = f->x * f->x;
		f->y2 = f->y * f->y;
		++(*iteration);
	}
}
