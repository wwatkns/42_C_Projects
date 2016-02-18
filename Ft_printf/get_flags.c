/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 10:48:38 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/18 11:11:14 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	init_flags(t_global *e)
{
	e->arg.flags.s = 0;
	e->arg.flags.m = 0;
	e->arg.flags.p = 0;
	e->arg.flags.d = 0;
	e->arg.flags.z = 0;
}

static int	is_flag(char c)
{
	return (c == ' ' || c == '+' || c == '-' || c == '#' || c == '0');
}

static int	flag_error(const char *format, int i)
{
	if (e->arg.flag.s && e->arg.flag.p)
		return (-1);
	if (e->arg.flag.z && e->arg.flag.m)
		return (-1);
	return (i);
}

int			get_flags(t_global *e, const char *format, int i)
{
	while (is_flag(format[i++]))
	{
		format[i] == ' ' ? e->arg.flags.s = 1 : 0;
		format[i] == '-' ? e->arg.flags.m = 1 : 0;
		format[i] == '+' ? e->arg.flags.p = 1 : 0;
		format[i] == '#' ? e->arg.flags.d = 1 : 0;
		format[i] == '0' ? e->arg.flags.z = 1 : 0;
	}
	return (flag_error(format, i));
}
