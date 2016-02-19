/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:53:53 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/19 17:54:22 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_arg_unsigned(t_e *e, t_a *arg, int *i)
{
	char	pad;

	pad = arg->flag.sp == 1 ? ' ' : '\0';
	pad = arg->flag.pl == 1 ? '+' : pad;
	if (arg->type == 'u' && arg->mod.hh)
		*i = print_unsigned_int((unsigned char)
			va_arg(e->ap, unsigned int), pad, arg);
	else if (arg->type == 'u' && arg->mod.h)
		*i = print_unsigned_int((unsigned short)
			va_arg(e->ap, unsigned int), pad, arg);
	else if (arg->type == 'u' && arg->mod.j)
		*i = print_unsigned_int(va_arg(e->ap, uintmax_t), pad, arg);
	else if (arg->type == 'u' && arg->mod.z)
		*i = print_unsigned_int(va_arg(e->ap, size_t), pad, arg);
	else if (arg->type == 'u' && arg->mod.ll)
		*i = print_unsigned_int(va_arg(e->ap, unsigned long long), pad, arg);
	else if (arg->type == 'U' || ((arg->type == 'u' && arg->mod.l)))
		*i = print_unsigned_int(va_arg(e->ap, unsigned long), pad, arg);
	else if (arg->type == 'u')
		*i = print_unsigned_int(va_arg(e->ap, unsigned int), pad, arg);
}
