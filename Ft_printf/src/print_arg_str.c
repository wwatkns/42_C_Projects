/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 18:03:02 by wwatkins          #+#    #+#             */
/*   Updated: 2016/03/03 19:30:55 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_arg_str(t_e *e, t_a *arg, int *i)
{
	while (arg->prec.pt && arg->prec.prec == 0 && arg->width > 0)
	{
		write(1, " ", 1);
		arg->width--;
		e->plen++;
	}
	if (arg->mod.l || arg->type == 'S')
		*i = print_str_wchar_t(va_arg(e->ap, wchar_t *), arg);
	else
		*i = print_str(va_arg(e->ap, char *), arg);
}
