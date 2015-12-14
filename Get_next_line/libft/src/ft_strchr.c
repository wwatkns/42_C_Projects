/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:15:55 by wwatkins          #+#    #+#             */
/*   Updated: 2015/11/29 19:27:08 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)c == s[i])
			return ((char*)&s[i]);
		i++;
	}
	if ((unsigned char)c == 0)
		return ((char*)&s[i]);
	return (0);
}
