/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 09:40:27 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/18 10:05:59 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_int(long long int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
		write(1, "-", 1);
	}
	n > 9 ? len += print_int(n / 10) : 0;
	print_char(n % 10 + '0');
	return (len);
}
