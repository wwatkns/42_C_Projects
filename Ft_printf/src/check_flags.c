/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:47:02 by wwatkins          #+#    #+#             */
/*   Updated: 2016/03/03 19:39:55 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_isdigit(char c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

int	check_zero(t_a *arg)
{
	if (arg->flag.zr == 1 && arg->type == 'p')
		return (-1);
	if (arg->flag.zr == 1 && arg->flag.mn == 1)
		arg->flag.zr = 0;
	if (arg->flag.zr == 1 && arg->prec.pt == 1 && (arg->type == 'd' ||
		arg->type == 'i' || arg->type == 'o' || arg->type == 'u' ||
		arg->type == 'x' || arg->type == 'X' || arg->type == 'D'))
		arg->flag.zr = 0;
	return (0);
}

int	check_space(t_a *arg)
{
	if (arg->flag.sp == 1 && !(arg->type == '%' || ft_isdigit(arg->type)))
		return (-1);
	if (arg->flag.sp == 1 && arg->flag.di == 1 && arg->type != '%' &&
		arg->type != 'R')
		return (-1);
	if (arg->flag.sp == 1 && arg->flag.pl == 1 && arg->type != '%' &&
		arg->type != 'R')
		arg->flag.sp = 0;
	return (0);
}

int	check_plus(t_a *arg)
{
	if (arg->flag.pl == 1 && !(arg->type == 'd' || arg->type == 'D' ||
		arg->type == 'i' || arg->type == '%' || arg->type == 'R' ||
		arg->type == 'u' || arg->type == 'o' || arg->type == 'O' ||
		arg->type == 's' || arg->type == 'S' || arg->type == 'p'))
		return (-1);
	return (0);
}

int	check_diez(t_a *arg)
{
	if (arg->flag.di == 1 && !(arg->type == 'o' || arg->type == 'O' ||
		arg->type == 'x' || arg->type == 'X' || arg->type == '%' ||
		arg->type == 'R'))
		return (-1);
	return (0);
}
