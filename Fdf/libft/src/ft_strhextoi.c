/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhextoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:39:55 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/05 14:46:47 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strhextoi(char *str)
{
	int i;
	int e;
	int hex;

	i = ft_strlen(str);
	e = 1;
	hex = 0;
	while (--i >= 0 && e <= 1048576)
	{
		if (ft_isdigit(str[i]))
			hex += (str[i] - '0') * e;
		else if ('a' <= str[i] && str[i] <= 'f')
			hex += (str[i] - 'a') * e;
		else if ('A' <= str[i] && str[i] <= 'F')
			hex += (str[i] - 'A') * e;
		e *= 16;
	}
	return (hex);
}
