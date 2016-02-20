/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_wchar_t.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 12:04:27 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/20 13:04:17 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int  nbr_binary(unsigned int v)
{
	int i;

	i = 1;
	while (v >>= 1)
		i++;
	return (i / 4);
}

static int	wchar_t_str_len(const wchar_t *s)
{
	int	len;

	len = 0;
	while (*s != '\0')
		len += nbr_binary(*s++);
	return (len);
}

int		print_str_wchar_t(const wchar_t *s, t_a *arg)
{
	int	len;

	len = wchar_t_str_len(s);
	if (arg->prec.pt && arg->prec.prec == 0)
		return (arg->width);
	arg->prec.prec = (arg->prec.prec == 0 || arg->prec.prec > len ? len :
			arg->prec.prec);
	arg->width -= arg->prec.prec;
	len += arg->width;
	while (arg->width-- > 0)
		write(1, " ", 1);
	while (*s != 0 && arg->prec.prec-- > 0)
		print_wchar_t(*s++);
	return (len);
}
