/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:50:37 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/20 12:54:11 by wwatkins         ###   ########.fr       */
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

int			parse_format(const char *format, t_a *arg, t_e *e)
{
	int	i;

	i = 0;
	init_arg(arg);
	i = get_flags(format, i, arg);
	i = get_width(format, i, arg);
	i = get_prec(format, i, arg);
	i = get_mod(format, i, arg);
	if ((i = get_type(format, i, arg)) == -1)
		return (-1);
	if ((check_err(arg) == -1))
		return (-1);
	e->alen += i;
	return (0);
}
