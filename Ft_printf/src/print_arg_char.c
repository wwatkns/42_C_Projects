/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:52:21 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/20 11:41:40 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_arg_char(t_e *e, t_a *arg, int *i)
{
	while (--arg->width > 0)
	{
		write(1, " ", 1);
		*i += 1;
	}
	if (arg->mod.l || arg->type == 'C')
		*i = print_wchar_t(va_arg(e->ap, wchar_t));
	else
		*i = print_char(va_arg(e->ap, int));
}
