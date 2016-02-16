/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:39:36 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/16 15:13:43 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	char	*s;
	char	c;
	int		i;

	va_start(ap, format);
	while (*format != '\0')
	{
		if (ft_strnstr(&(*format), "%s", 2))
		{
			s = va_arg(ap, char*);
			ft_putstr(s);
			format++;
		}
		else if (ft_strnstr(&(*format), "%d", 2))
		{
			i = va_arg(ap, int);
			ft_putnbr(i);
			format++;
		}
		else if (ft_strnstr(&(*format), "%c", 2))
		{
			c = va_arg(ap, int);
			ft_putchar(c);
			format++;
		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end(ap);
}

int		main(void)
{
	ft_printf("%s, %s\n%d\n%c\n", "ok", "toto", 15, 'Z');
	return (0);
}
