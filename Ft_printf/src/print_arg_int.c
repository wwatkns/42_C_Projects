/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:52:38 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/23 09:53:27 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static long long int	int_mod(t_e *e, t_a *arg)
{
	if ((arg->type == 'd' || arg->type == 'i') && arg->mod.hh)
		return ((char)va_arg(e->ap, int));
	if ((arg->type == 'd' || arg->type == 'i') && arg->mod.h)
		return ((short)va_arg(e->ap, int));
	if (arg->type == 'D' || ((arg->type == 'd' || arg->type == 'i')
		&& arg->mod.l))
		return (va_arg(e->ap, long int));
	if ((arg->type == 'd' || arg->type == 'i') && arg->mod.ll)
		return (va_arg(e->ap, long long int));
	if ((arg->type == 'd' || arg->type == 'i') && arg->mod.j)
		return (va_arg(e->ap, intmax_t));
	if ((arg->type == 'd' || arg->type == 'i') && arg->mod.z)
		return (va_arg(e->ap, size_t));
	return (va_arg(e->ap, int));
}

void					print_arg_int(t_e *e, t_a *arg, int *i)
{
	long long int	va;

	if (arg->prec.pt && arg->prec.prec == 0)
		return ;
	va = int_mod(e, arg);
	*i = print_int(va, arg);
	while (arg->flag.mn && arg->width > 0 && (arg->width--))
	{
		write(1, " ", 1);
		(*i)++;
	}
}
