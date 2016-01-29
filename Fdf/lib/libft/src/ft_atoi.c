/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:43:57 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/03 13:22:43 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int j;
	int sign;
	int value;

	j = 0;
	sign = 0;
	value = 0;
	while (ft_isblank(str[j]))
		j++;
	i = j;
	while (str[i] != '\0')
	{
		if ('0' <= str[i] && str[i] <= '9')
			value = (value * 10) + str[i] - '0';
		else if (str[i] == '+' && i == j)
			sign = 0;
		else if (str[i] == '-' && i == j)
			sign = 1;
		else
			break ;
		i++;
	}
	return (sign == 0 ? value : -value);
}
