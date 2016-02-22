/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:51:45 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/22 10:16:30 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static unsigned long long	base_mod(t_e *e, t_a *arg)
{
	if (arg->mod.hh)
		return ((char)va_arg(e->ap, int));
	if (arg->mod.h)
		return ((unsigned short)va_arg(e->ap, int));
	if (arg->mod.l)
		return (va_arg(e->ap, unsigned long int));
	if (arg->mod.ll)
		return (va_arg(e->ap, unsigned long long int));
	if (arg->mod.j)
		return (va_arg(e->ap, uintmax_t));
	if (arg->mod.z)
		return (va_arg(e->ap, size_t));
	return (va_arg(e->ap, unsigned int));
}

void	print_arg_base(t_e *e, t_a *arg, int *i)
{
	unsigned long long	va;

	va = base_mod(e, arg);
	if (arg->type == 'o' || arg->type == 'O')
		*i = print_base(arg, va, 8, 'a');
	else if (arg->type == 'x')
		*i = print_base(arg, va, 16, 'a');
	else if (arg->type == 'X')
		*i = print_base(arg, va, 16, 'A');
	while (arg->flag.mn && arg->width-- > 0 && (write(1, " ", 1)))
		e->plen++;
}
