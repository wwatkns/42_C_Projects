/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_len_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:56:46 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/19 17:56:58 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	nbr_len_unsigned(unsigned long long int n)
{
	int	len;

	len = 1;
	if (n == 0)
		return (1);
	while ((n /= 10) > 0)
		len++;
	return (len);
}
