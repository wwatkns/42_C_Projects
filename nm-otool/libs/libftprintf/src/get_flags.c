/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:48:57 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/21 11:37:06 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	get_flags(const char *format, int i, t_a *arg)
{
	while (is_flag(format[i]))
	{
		format[i] == ' ' ? arg->flag.sp = 1 : 0;
		format[i] == '+' ? arg->flag.pl = 1 : 0;
		format[i] == '-' ? arg->flag.mn = 1 : 0;
		format[i] == '#' ? arg->flag.di = 1 : 0;
		format[i] == '0' ? arg->flag.zr = 1 : 0;
		i++;
	}
	return (i);
}
