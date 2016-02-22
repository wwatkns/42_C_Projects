/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:58:13 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/22 14:54:27 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_spaces(t_a *arg, int nbrlen, int sign)
{
	int	len;

	len = 0;
	arg->prec.prec = (arg->prec.prec > nbrlen ? arg->prec.prec : nbrlen);
	arg->width -= arg->prec.prec;
	arg->width -= ((arg->flag.pl && sign == 0) || sign == -1 ? 1 : 0);
	while (!arg->flag.mn && arg->width > 0 && (arg->width--))
	{
		write(1, " ", 1);
		len++;
	}
	sign == -1 ? write(1, "-", 1) : 0;
	arg->flag.pl && sign == 0 ? write(1, "+", 1) : 0;
	arg->flag.pl && sign == 0 ? len++ : 0;
	while ((arg->prec.prec - nbrlen) > 0 && (arg->prec.prec--))
	{
		write(1, "0", 1);
		len++;
	}
	return (len);
}

int		print_int(long long int n, t_a *arg)
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
	{
		len += print_spaces(arg, depth, sign);
	}
	print_char(n % 10 + '0');
	sign = 0;
	return (len);
}

/*
static int	print_prec(long long int *n, char pad, t_a *arg)
{
	int	i;
	int	len;

	len = arg->prec.prec - nbr_len(*n);
	i = len + arg->width;
	while (arg->width-- > 0)
		write(1, " ", 1);
	if (pad != '\0' && *n > 0 && (i++))
		write(1, &pad, 1);
	if (*n < 0)
	{
		*n = -*n;
		write(1, "-", 1);
		i++;
	}
	while (--len >= -1)
		write(1, "0", 1);
	arg->prec.prec = 0;
	return (i < 0 ? 0 : i);
}

int			print_int(long long int n, char pad, t_a *arg)
{
	int	len;

	len = 1;
	len += print_prec(&n, pad, arg);
	n > 9 ? len += print_int(n / 10, '\0', arg) : 0;
	print_char(n % 10 + '0');
	return (len);
}*/
