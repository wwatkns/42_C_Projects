/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:52:49 by wwatkins          #+#    #+#             */
/*   Updated: 2016/11/05 17:16:06 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	scalar;

	scalar = nb % 2 == 0 ? 2 : 1;
	if (nb <= 0 || nb == 2)
		return (0);
	if (nb == 1)
		return (1);
	while (scalar <= nb / 2)
	{
		if (scalar * scalar == nb)
			return (scalar);
		scalar += 2;
	}
	return (0);
}
