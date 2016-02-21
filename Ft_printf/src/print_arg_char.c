/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:52:21 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/21 16:26:23 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_arg_char(t_e *e, t_a *arg, int *i)
{
	wchar_t	c;

	if (arg->mod.l || arg->type == 'C')
	{
		c = va_arg(e->ap, wchar_t);
		arg->width -= nbr_binary(c);
	}
	else
		arg->width--;
	while (!arg->flag.mn && arg->width--)
	{
		write(1, " ", 1);
		e->plen++;
	}
	if (arg->mod.l || arg->type == 'C')
		*i = print_wchar_t(c);
	else
		*i = print_char(va_arg(e->ap, int));
	while (arg->flag.mn && arg->width--)
	{
		write(1, " ", 1);
		e->plen++;
	}
}
