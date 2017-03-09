/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:48:34 by wwatkins          #+#    #+#             */
/*   Updated: 2016/03/04 16:37:07 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	write_else(t_e *e, const char *format)
{
	write(1, &format[e->alen++], 1);
	e->plen++;
}

int			ft_printf(const char *restrict format, ...)
{
	t_e		e;
	t_a		arg;

	e.alen = 0;
	e.plen = 0;
	va_start(e.ap, format);
	while (format && format[e.alen] != 0)
	{
		if (format[e.alen] == '%')
		{
			if (format[++e.alen] != '%')
			{
				if (parse_format(&format[e.alen], &arg, &e) == -1)
					return (e.plen = (e.plen == 0 ? 1 : e.plen));
				arg.null == 0 ? e.plen += print_arg(&e, &arg) : 0;
			}
			else if (format[e.alen] == '%' && (write(1, &format[e.alen++], 1)))
				e.plen++;
		}
		else
			write_else(&e, format);
	}
	va_end(e.ap);
	return (e.plen);
}
