/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:59:38 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/21 12:23:23 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_str(const char *s, t_a *arg)
{
	int	len;

	len = str_len(s);
	if (arg->prec.pt == 1 && arg->prec.prec == 0)
		return (arg->width);
	arg->prec.prec = (arg->prec.prec == 0 || arg->prec.prec > len ? len : arg->prec.prec);
	len = (arg->width > arg->prec.prec ? arg->width : arg->prec.prec);
	arg->width -= arg->prec.prec;
	while (!arg->flag.mn && arg->width-- > 0)
		write(1, " ", 1);
	while (*s != 0 && arg->prec.prec-- > 0)
		write(1, s++, 1);
	while (arg->flag.mn && arg->width-- > 0)
		write(1, " ", 1);
	return (len);
}
