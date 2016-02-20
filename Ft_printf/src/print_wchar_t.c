/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 11:26:12 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/20 12:07:53 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	print_mask_1(unsigned int *mask, unsigned int v)
{
	unsigned char	o2;
	unsigned char	o1;
	unsigned char	octet;

	o2 = (v << 26) >> 26;
	o1 = ((v >> 6) << 27) >> 27;
	octet = (mask[1] >> 8) | o1;
	write(1, &octet, 1);
	octet = ((mask[1] << 24) >> 24) | o2;
	write(1, &octet, 1);
}

static void	print_mask_2(unsigned int *mask, unsigned int v)
{
	unsigned char	o3;
	unsigned char	o2;
	unsigned char	o1;
	unsigned char	octet;

	o3 = (v << 26) >> 26;
	o2 = ((v >> 6) << 26) >> 26;
	o1 = ((v >> 12) << 28) >> 28;
	octet = (mask[2] >> 16) | o1;
	write(1, &octet, 1);
	octet = ((mask[2] << 16) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask[2] << 24) >> 24) | o3;
	write(1, &octet, 1);
}

static void	print_mask_3(unsigned int *mask, unsigned int v)
{
	unsigned char	o4;
	unsigned char	o3;
	unsigned char	o2;
	unsigned char	o1;
	unsigned char	octet;

	o4 = (v << 26) >> 26;
	o3 = ((v >> 6) << 26) >> 26;
	o2 = ((v >> 12) << 26) >> 26;
	o1 = ((v >> 18) << 29) >> 29;
	octet = (mask[3] >> 24) | o1;
	write(1, &octet, 1);
	octet = ((mask[3] << 8) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask[3] << 16) >> 24) | o3;
	write(1, &octet, 1);
	octet = ((mask[3] << 24) >> 24) | o4;
	write(1, &octet, 1);
}

static int	nbr_binary(unsigned int v)
{
	int i;

	i = 1;
	while (v >>= 1)
		i++;
	return (i);
}

int			print_wchar_t(wchar_t c)
{
	unsigned int	mask[4];
	unsigned int	v;
	int				size;
	unsigned char	octet;

	v = c;
	size = nbr_binary(c);
	mask[0] = 0;
	mask[1] = 49280;
	mask[2] = 14712960;
	mask[3] = 4034953344;
	if (size <= 7)
	{
		octet = c;
		write(1, &octet, 1);
	}
	else if (size <= 11)
		print_mask_1(mask, v);
	else if (size <= 16)
		print_mask_2(mask, v);
	else
		print_mask_3(mask, v);
	return (size / 4);
}
