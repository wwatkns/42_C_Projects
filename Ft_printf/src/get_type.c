/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:50:04 by wwatkins          #+#    #+#             */
/*   Updated: 2016/03/03 16:49:12 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	get_type(const char *format, int i, t_a *arg)
{
	arg->type = format[i];
	if (is_type(format[i]))
		return (i + 1);
	return (i);
}
