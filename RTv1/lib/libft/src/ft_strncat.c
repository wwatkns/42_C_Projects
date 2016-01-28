/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:28:48 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/03 12:54:34 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;
	size_t len;

	j = -1;
	len = ft_strlen(s1);
	i = len - 1;
	while (++i < len + n && s2[++j] != '\0')
		s1[i] = s2[j];
	s1[i] = '\0';
	return (s1);
}
