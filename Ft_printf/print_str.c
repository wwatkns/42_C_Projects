/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 16:47:27 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/17 17:09:21 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_str(const char *s, int max)
{
	int		len;

	len = str_len(s);
	max > 0 && max < len ? len = max : 0;
	write(1, s, len);
	return (len);
}
