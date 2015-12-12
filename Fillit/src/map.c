/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 08:32:51 by scollon           #+#    #+#             */
/*   Updated: 2015/12/11 14:58:46 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_allocmap(void)
{
	int		i;
	char	**map;

	i = 0;
	ft_error((int)(map = (char**)malloc(sizeof(char*) * 16)));
	while (i < 16)
	{
		ft_error((int)(map[i] = ft_strnew(16)));
		i++;
	}
	return (map);
}

void	ft_setmap(char **map, size_t size)
{
	int x;
	int y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (!ft_isalpha(map[y][x]))
				map[y][x] = '.';
			x++;
		}
		y++;
	}
}

void	ft_printmap(char **map, size_t size)
{
	int x;
	int y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_putchar(map[y][x]);
			ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

void	ft_mapclr(char **map, size_t size)
{
	int x;
	int y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			map[y][x] = '.';
			x++;
		}
		y++;
	}
}

size_t	ft_optiminsquare(size_t ret)
{
	size_t	n;
	size_t	minsquare;

	n = 4 * ((ret + 1) / 21);
	minsquare = 2;
	while (minsquare <= 16)
	{
		if (minsquare * minsquare >= n)
			break ;
		minsquare++;
	}
	return (minsquare);
}
