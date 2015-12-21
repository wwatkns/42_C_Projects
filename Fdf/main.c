/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:27:53 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/21 19:15:39 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_puttab(int **tab, int tabwidth)
{
	int x;
	int y;

	y = 0;
	while (tab[y] != NULL)
	{
		x = 0;
		while (x < tabwidth)
		{
			ft_putnbr(tab[y][x]);
			ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

int		main(int argc, char **argv)
{
	int		tabwidth;
	int		**tab;

	if (argc != 2)
		ft_error(0);
	tabwidth = 0;
	tab = ft_read(argv[1], &tabwidth);
	ft_mlxmain(tab, tabwidth);
	//ft_puttab(tab, tabwidth);
	free(tab);
	return (0);
}
