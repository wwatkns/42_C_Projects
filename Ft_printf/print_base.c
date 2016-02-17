/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 15:54:56 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/17 16:10:30 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_base(long n, const int base, char maj)
{
	int		len;
	int		cal;
	char	c;

	if (base < 2 || base > 16)
		return (-1);
	n < 0 ? n = -n : 0;
	len = 0;
	while (n > 0)
	{
		cal = (n % base);
		c = (cal > 9 ? cal - 10 + maj : cal + '0');
		write(1, &c, 1);
		n /= base;
		len++;
	}
	return (len);
}
