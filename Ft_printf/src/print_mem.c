/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:59:17 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/19 17:59:32 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_mem(void *p, t_a *arg)
{
	int	len;
	int	plen;

	len = 2;
	plen = len + nbr_len_base((long)p, 16);
	arg->width -= plen;
	while (--arg->width >= 0 && len++)
		write(1, " ", 1);
	write(1, "0x", 2);
	len += print_base((long)p, 16, 'a');
	return (len);
}
