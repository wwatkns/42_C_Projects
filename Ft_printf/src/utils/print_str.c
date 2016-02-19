/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:59:38 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/19 18:00:06 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_str(const char *s, int width, int prec)
{
	int	len;

	prec = prec < 1 ? str_len(s) : prec;
	len = width + prec;
	width -= prec;
	while (width-- > 0)
		write(1, " ", 1);
	while (*s != 0 && prec-- > 0)
		write(1, s++, 1);
	while (prec-- > 0)
		write(1, " ", 1);
	return (len);
}
