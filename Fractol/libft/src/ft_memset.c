/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:22:15 by wwatkins          #+#    #+#             */
/*   Updated: 2015/11/29 17:59:41 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*bt;

	i = 0;
	bt = (char*)b;
	while (i < len)
	{
		bt[i] = (unsigned char)c;
		i++;
	}
	return (bt);
}
