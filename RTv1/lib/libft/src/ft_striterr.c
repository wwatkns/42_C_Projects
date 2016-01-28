/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striterr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 16:35:56 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/28 16:43:07 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_striterr(char *s, int (*f)(char *))
{
	unsigned int i;

	i = 0;
	if (s == NULL || f == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (f(&s[i]))
			return (1);
		i++;
	}
	return (0);
}
