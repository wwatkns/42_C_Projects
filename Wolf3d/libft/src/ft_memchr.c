/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:31:36 by wwatkins          #+#    #+#             */
/*   Updated: 2015/11/30 14:36:32 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*st;
	unsigned char	ct;

	i = 0;
	st = (unsigned char*)s;
	ct = (unsigned char)c;
	while (i < n)
	{
		if (st[i] == ct)
			return (&st[i]);
		i++;
	}
	return (NULL);
}
