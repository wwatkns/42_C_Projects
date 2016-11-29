/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:02:27 by wwatkins          #+#    #+#             */
/*   Updated: 2016/11/23 17:06:25 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int index;
	int count;

	index = 0;
	count = 0;
	while (tab[index])
	{
		if (f(tab[index]) == 1)
			count++;
		index++;
	}
	return (count);
}
