/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:48:34 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/22 17:03:59 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h> // Temporary

int		ft_printf(const char *restrict format, ...)
{
	t_e		e;
	t_a		arg;

	setlocale(LC_ALL, "en_US.UTF-8");
	e.alen = 0;
	e.plen = 0;
	va_start(e.ap, format);
	while (format[e.alen] != 0)
	{
		if (format[e.alen] == '%')
		{
			if (format[++e.alen] != '%')
			{
				if (parse_format(&format[e.alen], &arg, &e) == -1)
					return (e.plen);
				e.plen += print_arg(&e, &arg);
			}
			else if (format[e.alen] == '%' && (write(1, &format[e.alen++], 1)))
				e.plen++;
		}
		else
		{
			write(1, &format[e.alen++], 1);
			e.plen++;
		}
	}
	va_end(e.ap);
	return (e.plen);
}

int		main(void)
{
//	printf("%d\n", ft_printf("%40.8ls\n", L"xavierÕÕÕ"));
//	printf("%d\n", printf("%40.8ls\n", L"xavierÕÕÕ"));
//	printf("%d\n", ft_printf("%40.12s %-8.5s\n", "totot", NULL));
//	printf("%d\n", printf("%40.12s %-8.5s\n", "totot", NULL));
//	printf("%d\n", ft_printf("%llx\n", (unsigned long long)42949672964848999));
//	printf("%d\n", printf("%llx\n", (unsigned long long)42949672964848999));
	printf("\n%d\n", ft_printf("@moulitest: %s\n", NULL));
	printf("\n%d\n", printf("@moulitest: %s\n", NULL));
	return (0);
}
