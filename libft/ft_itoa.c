/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:10:11 by wwatkins          #+#    #+#             */
/*   Updated: 2015/11/30 15:10:28 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		i;
	int		sign;
	int		size;
	char	*new;

	if (n == -2147483648)
		return ("-2147483648");
	i = 0;
	size = ft_nbrlen(n);
	sign = (n < 0 ? 1 : 0);
	if (n < 0)
		n *= -1;
	if (!(new = (char*)malloc(sizeof(char) *
		(sign == 1 ? size + 1 : size) + 1)))
		return (NULL);
	while (i < size)
	{
		new[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	if (sign == 1)
		new[size] = '-';
	return (ft_strrev(new, (sign == 1 ? size + 1 : size)));
}
