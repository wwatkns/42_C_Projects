/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:58:13 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/22 17:09:34 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_spaces(t_a *arg, int nbrlen, int sign)
{
	int	len;

	len = 0;
	arg->flag.sp && sign == 0 && arg->width <= nbrlen ? write(1, " ", 1) : 0;
	arg->flag.sp && sign == 0 && arg->width <= nbrlen ? len++ : 0;
	arg->prec.prec = (arg->prec.prec > nbrlen ? arg->prec.prec : nbrlen);
	arg->width -= arg->prec.prec;
	arg->width -= ((arg->flag.pl && sign == 0) || sign == -1 ? 1 : 0);
	arg->flag.zr && sign == -1 ? write(1, "-", 1) : 0;
	arg->flag.zr && arg->flag.pl && sign == 0 ? write(1, "+", 1) : 0;
	while (!arg->flag.mn && arg->width > 0 && (arg->width--))
	{
		arg->flag.zr ? write(1, "0", 1) : write(1, " ", 1);
		len++;
	}
	!arg->flag.zr && sign == -1 ? write(1, "-", 1) : 0;
	!arg->flag.zr && arg->flag.pl && sign == 0 ? write(1, "+", 1) : 0;
	arg->flag.pl && sign == 0 ? len++ : 0;
	while ((arg->prec.prec - nbrlen) > 0 && (arg->prec.prec--))
	{
		write(1, "0", 1);
		len++;
	}
	return (len);
}

int			print_int(long long int n, t_a *arg)
{
	int						len;
	static int				sign = 0;
	static long long int	depth = 0;

	depth++;
	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
		sign = -1;
	}
	if (n > 9)
		len += print_int(n / 10, arg);
	if (n <= 9 && n >= 0)
		len += print_spaces(arg, depth, sign);
	print_char(n % 10 + '0');
	sign = 0;
	return (len);
}