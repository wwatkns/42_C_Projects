/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:25:45 by wwatkins          #+#    #+#             */
/*   Updated: 2015/11/26 10:09:17 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*new;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(new = (char*)malloc(sizeof(char) * (len1 + len2))))
		return (NULL);
	while (i < len1 + len2)
	{
		if (i < len1)
			new[i] = s1[i];
		else
			new[i] = s2[i - len1];
		i++;
	}
	new[i] = '\0';
	return (new);
}
