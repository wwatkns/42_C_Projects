/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 10:20:36 by scollon           #+#    #+#             */
/*   Updated: 2015/12/13 10:40:33 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_resolve(char **map, t_tris *tetri, size_t size, int nb)
{
	int		n;
	int		sol[nb];
	t_var	t;

	t.nb = nb;
	t.size = size;
	t.tetri = tetri;
	ft_initsol(sol, nb);
	while (size < 16)
	{
		n = 0;
		ft_setmap(map, t.size);
		if (ft_solswap(map, t, sol, 0))
			break ;
		t.size++;
	}
}

int		ft_checksol(char **map, t_tris *tetri, int nb, int size)
{
	int x;
	int y;
	int p;

	p = 0;
	y = 0;
	while (y <= size)
	{
		x = 0;
		while (x <= size)
		{
			p = (ft_isalpha(map[y][x]) ? p + 1 : p);
			x++;
		}
		y++;
	}
	return (p == nb * 4 ? 1 : 0);
}

int		ft_solswap(char **map, t_var t, int *sol, int i)
{
	int j;
	int n;

	n = 0;
	if ((j = i) && i == t.nb)
	{
		ft_mapclr(map, t.size);
		while (n < t.nb && ft_placet(map, t.tetri[sol[n]], t.size))
			n++;
		if (ft_checksol(map, t.tetri, t.nb, t.size))
		{
			ft_printmap(map, t.size);
			return (1);
		}
		return (0);
	}
	while (j < t.nb)
	{
		ft_swapindex(&sol[i], &sol[j]);
		if (ft_solswap(map, t, sol, i + 1))
			return (1);
		ft_swapindex(&sol[i], &sol[j]);
		j++;
	}
	return (0);
}

void	ft_initsol(int *sol, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		sol[i] = i;
		i++;
	}
}

void	ft_swapindex(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}
