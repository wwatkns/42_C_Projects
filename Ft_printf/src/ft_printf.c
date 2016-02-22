/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:48:34 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/22 14:05:38 by wwatkins         ###   ########.fr       */
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
	printf("------------ TEST1 -------------\n");
	printf("\n%d\n", ft_printf("%d %d", 1, -29));
	printf("\n%d\n", printf("%d %d", 1, -29));
	printf("------------ TEST2 -------------\n");
	printf("\n%d\n", ft_printf("%10.3d % .8d", 4859, -29888));
	printf("\n%d\n", printf("%10.3d % .8d", 4859, -29888));
	printf("------------ TEST3 -------------\n");
	printf("\n%d\n", ft_printf("%021d %-3.2d", 486135168, 4159));
	printf("\n%d\n", printf("%021d %-3.2d", 486135168, 4159));
	printf("------------ TEST4 -------------\n");
	printf("\n%d\n", ft_printf("%d %d", 1, -29));
	printf("\n%d\n", printf("%d %d", 1, -29));
	return (0);
}
