/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 10:29:22 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/18 10:55:16 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_format(t_global *e, const char *format)
{
	int	i;

	i = 0;
	if (*(format + 1) == '%')
		return (1);
	i += get_flags(e, format, i);
	i += get_width(e, format, i);
	i += get_prec(e, format, i);
	i += get_mod(e, format, i);
	i += get_type(e, format, i);
	return (i);
}
