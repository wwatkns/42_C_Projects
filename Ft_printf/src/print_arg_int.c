/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:52:38 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/22 12:28:27 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_arg_int(t_e *e, t_a *arg, int *i)
{
	char	pad;

	pad = arg->flag.sp == 1 ? ' ' : '\0';
	pad = arg->flag.pl == 1 ? '+' : pad;
	if ((arg->type == 'd' || arg->type == 'i') && arg->mod.hh)
		*i = print_int((signed char)va_arg(e->ap, int), pad, arg);
	else if ((arg->type == 'd' || arg->type == 'i') && arg->mod.h)
		*i = print_int((short)va_arg(e->ap, int), pad, arg);
	else if ((arg->type == 'd' || arg->type == 'i') && arg->mod.j)
		*i = print_int(va_arg(e->ap, intmax_t), pad, arg);
	else if ((arg->type == 'd' || arg->type == 'i') && arg->mod.z)
		*i = print_int(va_arg(e->ap, size_t), pad, arg);
	else if ((arg->type == 'd' || arg->type == 'i') && arg->mod.ll)
		*i = print_int(va_arg(e->ap, long long), pad, arg);
	else if (arg->type == 'D' || ((arg->type == 'd' ||
			arg->type == 'i') && arg->mod.l))
		*i = print_int(va_arg(e->ap, long), pad, arg);
	else if (arg->type == 'd' || arg->type == 'i')
		*i = print_int(va_arg(e->ap, int), pad, arg);
}
