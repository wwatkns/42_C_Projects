/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 10:07:59 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/18 10:08:37 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_unsigned_int(unsigned long long int n)
{
	int	len;

	len = 1;
	n > 9 ? len += print_unsigned_int(n / 10) : 0;
	print_char(n % 10 + '0');
	return (len);
}
