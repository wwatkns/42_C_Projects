/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:48:34 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/19 18:11:24 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		ft_printf(const char *restrict format, ...)
{
	t_e		e;
	t_a		arg;

	e.alen = 0;
	e.plen = 0;
	va_start(e.ap, format);
	while (format[e.alen] != 0)
	{
		if (format[e.alen] == '%' && !(e.alen > 0 && format[e.alen - 1] == '%'))
		{
			if (format[++e.alen] != '%')
			{
				if (parse_format(&format[e.alen], &arg, &e) == -1)
					return (-1);
				e.plen += print_arg(&e, &arg);
			}
			else if (e.plen++)
				write(1, &format[e.alen++], 1);
		}
		else if (e.plen++)
			write(1, &format[e.alen++], 1);
	}
	va_end(e.ap);
	return (e.plen);
}

int		main(void)
{
	ft_printf("%dtoto %%p\n", 10);
	printf("%dtoto %%p\n", 10);
	return (0);
}
