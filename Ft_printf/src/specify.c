/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specify.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:54:30 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/19 18:03:38 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	is_mod(char md)
{
	return (md == 'l' || md == 'h' || md == 'j' || md == 'z');
}

int	is_flag(char fl)
{
	return (fl == ' ' || fl == '+' || fl == '-' || fl == '#' || fl == '0');
}

int	is_type(char ty)
{
	if (ty == 'd' || ty == 'D' || ty == 's' || ty == 'S' || ty == 'x' ||
		ty == 'X' || ty == 'p' || ty == 'o' || ty == 'O' || ty == 'c' ||
		ty == 'C' || ty == 'u' || ty == 'U' || ty == 'i')
		return (1);
	return (0);
}
