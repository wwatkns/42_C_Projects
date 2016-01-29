/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:42:54 by wwatkins          #+#    #+#             */
/*   Updated: 2015/11/26 14:45:59 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char out;

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			n = -n;
			write(fd, "-", 1);
		}
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		out = n % 10 + '0';
		write(fd, &out, 1);
	}
}
