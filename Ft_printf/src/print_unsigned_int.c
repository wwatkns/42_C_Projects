/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 18:00:15 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/21 16:06:56 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_uprec(unsigned long long int *n, char pad, t_a *arg)
{
	int	i;
	int	len;

	len = arg->prec.prec - nbr_len_unsigned(*n);
	arg->width -= len - 1;
	i = len + arg->width;
	while ((arg->width-- - len) > 0)
		write(1, " ", 1);
	if (pad != '\0' && *n > 0 && (i++))
		write(1, &pad, 1);
	while (--len >= 0)
		write(1, "0", 1);
	arg->prec.prec = 0;
	return (i < 0 ? 0 : i);
}

int			print_unsigned_int(unsigned long long int n, char pad, t_a *arg)
{
	int	len;

	len = 1;
	arg->prec.prec > 0 ? len += print_uprec(&n, pad, arg) : 0;
	n > 9 ? len += print_unsigned_int(n / 10, '\0', arg) : 0;
	print_char(n % 10 + '0');
	return (len);
}
