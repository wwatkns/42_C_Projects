/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:57:31 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/19 17:57:53 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_base(unsigned long long n, const int base, char maj)
{
	int		cal;
	int		len;
	char	c;

	len = 0;
	if (base < 2 || base > 16)
		return (-1);
	if (n > 0)
	{
		len = 1;
		cal = n % base;
		c = cal > 9 ? cal - 10 + maj : cal + '0';
		len += print_base(n / base, base, maj);
		write(1, &c, 1);
	}
	return (len);
}
