/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:50:20 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/21 11:42:05 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	get_width(const char *format, int i, t_a *arg)
{
	int	mult;
	int tmp;
	int re;

	re = 0;
	mult = 1;
	if (format[i] < '0' && format[i] > '9')
		return (i);
	tmp = i;
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	while (i > tmp)
	{
		re++;
		arg->width = arg->width + (format[--i] - '0') * mult;
		mult *= 10;
	}
	if (arg->width > INT_MAX || arg->width < 0)
		arg->width = 0;
	return (i + re);
}
