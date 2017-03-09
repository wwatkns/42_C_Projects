/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:57:31 by wwatkins          #+#    #+#             */
/*   Updated: 2016/03/04 12:19:55 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	prfx(t_a *arg)
{
	int	len;

	len = 0;
	if (arg->type == 'o' || arg->type == 'O')
	{
		write(1, "0", 1);
		len = 1;
	}
	else if (arg->type == 'x')
	{
		write(1, "0x", 2);
		len = 2;
	}
	else if (arg->type == 'X')
	{
		write(1, "0X", 2);
		len = 2;
	}
	return (len);
}

static int	print_spaces(t_a *arg, int len)
{
	int	sp;
	int	prefix_len;

	sp = 0;
	prefix_len = 0;
	arg->flag.di && arg->type == 'o' ? prefix_len = 1 : 0;
	arg->flag.di && arg->type == 'x' ? prefix_len = 2 : 0;
	arg->flag.di && arg->type == 'X' ? prefix_len = 2 : 0;
	arg->prec.prec = (arg->prec.prec > len ? arg->prec.prec : len);
	arg->type == 'o' && arg->flag.di && arg->prec.pt ?
	arg->prec.prec -= prefix_len : 0;
	arg->width -= arg->prec.prec + prefix_len;
	while (!arg->flag.mn && arg->width > 0)
	{
		arg->flag.zr ? write(1, "0", 1) : write(1, " ", 1);
		arg->width--;
		sp++;
	}
	while ((arg->prec.prec - len) > 0)
	{
		write(1, "0", 1);
		arg->prec.prec--;
		sp++;
	}
	return (sp);
}

int			print_base(t_a *arg, unsigned long long n, const int base, char maj)
{
	int				cal;
	int				len;
	char			c;
	static short	depth = 0;

	len = 0;
	if (n == 0 && depth == 0 && (write(1, "0", 1)))
		return (1);
	if (n > 0)
	{
		depth++;
		len = 1;
		cal = n % base;
		c = cal > 9 ? cal - 10 + maj : cal + '0';
		len += print_base(arg, n / base, base, maj);
		write(1, &c, 1);
	}
	if (n == 0)
	{
		(arg->flag.zr || arg->prec.pt) && arg->flag.di ? len += prfx(arg) : 0;
		len += print_spaces(arg, depth);
		!(arg->flag.zr || arg->prec.pt) && arg->flag.di ? len += prfx(arg) : 0;
	}
	depth = 0;
	return (len);
}
