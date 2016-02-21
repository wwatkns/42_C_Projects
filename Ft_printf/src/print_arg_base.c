/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:51:45 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/21 15:22:53 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_arg_base(t_e *e, t_a *arg, int *i)
{
	if (arg->type == 'o' || arg->type == 'O')
		*i = print_base(arg, va_arg(e->ap, int), 8, 'a');
	else if (arg->type == 'x')
		*i = print_base(arg, va_arg(e->ap, int), 16, 'a');
	else if (arg->type == 'X')
		*i = print_base(arg, va_arg(e->ap, int), 16, 'A');
	while (arg->flag.mn && arg->width-- > 0 && (write(1, " ", 1)))
		e->plen++;
}
