/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:01:11 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/18 11:06:28 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int argc, char **argv)
{
	if (argc != 1)
		exit(0);
	return (0);
}

void	ft_error(int err)
{
	if (err == 0 || err == -1)
	{
		ft_putendl_fd("error", 2);
		exit(0);
	}
}
