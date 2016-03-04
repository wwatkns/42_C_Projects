/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:50:37 by wwatkins          #+#    #+#             */
/*   Updated: 2016/03/04 10:34:19 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		init_arg(t_a *arg)
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
	arg->null = 0;
}

static	void	print_before(t_a *arg, t_e *e)
{
	if (arg->flag.mn == 0)
	{
		while (arg->width - arg->prec.prec > 0)
		{
			write(1, " ", 1);
			arg->width--;
			e->plen++;
		}
	}
}

static	void	print_after(t_a *arg, t_e *e)
{
	if (arg->flag.mn == 1)
	{
		while (arg->width - arg->prec.prec > 0)
		{
			write(1, " ", 1);
			arg->width--;
			e->plen++;
		}
	}
}

static void		check_arg(t_e *e, t_a *arg)
{
	va_list copy;

	va_copy(copy, e->ap);
	if (arg->type == 's' || arg->type == 'S')
	{
		if ((va_arg(copy, char *)) == NULL)
		{
			arg->null = 1;
			(arg->prec.pt == 0 && arg->prec.prec < 6) ? arg->prec.prec = 6 : 0;
			arg->prec.prec > 6 ? arg->prec.prec = 6 : 0;
			print_before(arg, e);
			write(1, "(null)", arg->prec.prec);
			e->plen += arg->prec.prec;
			print_after(arg, e);
		}
	}
	va_end(copy);
}

int				parse_format(const char *format, t_a *arg, t_e *e)
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
	check_arg(e, arg);
	e->alen += i;
	return (0);
}
