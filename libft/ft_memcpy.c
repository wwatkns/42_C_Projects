/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:49:26 by wwatkins          #+#    #+#             */
/*   Updated: 2015/11/30 15:38:00 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dstt;
	unsigned char	*srct;

	i = 0;
	dstt = (unsigned char*)dst;
	srct = (unsigned char*)src;
	while (i < n)
	{
		dstt[i] = srct[i];
		i++;
	}
	return (dst);
}
