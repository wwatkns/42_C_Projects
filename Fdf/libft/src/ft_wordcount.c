/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:41:37 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/06 13:00:10 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_wordcount(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (s[i] == 0 || (s[i] != c && i == 0))
		counter++;
	while (s[i] != 0)
	{
		if (s[i] != c && s[i - 1] == c)
			counter++;
		i++;
	}
	return (counter);
}
