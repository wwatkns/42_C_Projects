/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 10:11:54 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/03 18:15:46 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *s, int size)
{
	int		i;
	char	*srev;

	i = 0;
	if (!(srev = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	size--;
	while (size >= 0)
	{
		srev[i] = s[size];
		i++;
		size--;
	}
	srev[i] = '\0';
	return (srev);
}
