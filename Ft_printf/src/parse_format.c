/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:50:37 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/23 09:59:06 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	init_arg(t_a *arg)
{
	arg->flag.pl = 0;
	arg->flag.mn = 0;
	arg->flag.sp = 0;
	arg->flag.di = 0;
	arg->flag.zr = 0;
	arg->width = 0;
	arg->prec.pt = 0;
	arg->prec.prec = 0;
	arg->mod.h = 0;
	arg->mod.hh = 0;
	arg->mod.l = 0;
	arg->mod.ll = 0;
	arg->mod.j = 0;
	arg->mod.z = 0;
	arg->type = '\0';
}

static int	check_arg(t_e *e, t_a *arg)
{
	va_list	copy;

	va_copy(copy, e->ap);
	if (arg->type == 's')
	{
		if ((va_arg(copy, char *)) == NULL)
		{
			arg->prec.prec = (arg->prec.prec == 0 || arg->prec.prec > e->plen ?
					e->plen : arg->prec.prec);
			e->plen += arg->prec.prec;
			arg->width -= arg->prec.prec;
			while (!arg->flag.mn && arg->width-- > 0 && (write(1, " ", 1)))
				e->plen++;
			arg->prec.prec > 6 ? arg->prec.prec = 6 : 0;
			write(1, "(null)", arg->prec.prec);
			while (arg->flag.mn && arg->width-- > 0 && (write(1, " ", 1)))
				e->plen++;
			write(1, "\n", 1);
			e->plen++;
			return (-1);
		}
	}
	va_end(copy);
	return (0);
}

int			parse_format(const char *format, t_a *arg, t_e *e)
{
	int	i;

	i = 0;
	init_arg(arg);
	i = get_flags(format, i, arg);
	i = get_width(format, i, arg);
	i = get_prec(format, i, arg);
	i = get_mod(format, i, arg);
	i = get_type(format, i, arg);
	if ((check_err(arg) == -1))
		return (-1);
	if (check_arg(e, arg) == -1)
		return (-1);
	e->alen += i;
	return (0);
}
