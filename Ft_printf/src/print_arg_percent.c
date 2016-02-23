/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 10:41:20 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/23 10:05:48 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_arg_percent(t_e *e, t_a *arg, int *i)
{
	if (arg->prec.pt && arg->width == 0)
	{
		write(1, "%", 1);
		*i += 1;
		return ;
	}
	arg->width--;
	while (!arg->flag.mn && arg->width-- > 0)
	{
		arg->flag.zr ? write(1, "0", 1) : write(1, " ", 1);
		e->plen++;
	}
	write(1, "%", 1);
	*i += 1;
	while (arg->flag.mn && arg->width-- > 0)
	{
		write(1, " ", 1);
		e->plen++;
	}
}
