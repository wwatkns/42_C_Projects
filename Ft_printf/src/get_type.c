/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:50:04 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/19 17:50:14 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	get_type(const char *format, int i, t_a *arg)
{
	if (is_type(format[i]))
	{
		arg->type = format[i];
		return (i + 1);
	}
	return (-1);
}
