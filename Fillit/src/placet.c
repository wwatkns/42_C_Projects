/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 09:11:32 by scollon           #+#    #+#             */
/*   Updated: 2015/12/11 14:13:07 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_placet(char **map, t_tris tetri, size_t size)
{
	int		i;
	t_tris	tmp;

	i = 0;
	ft_tetricpy(&tmp, tetri);
	while (1)
	{
		if (ft_isplacable(map, tmp) == 4)
		{
			while (i < 4)
			{
				map[tmp.p[i].y][tmp.p[i].x] = tetri.name;
				i++;
			}
			return (1);
		}
		else
		{
			if (!ft_movet(&tmp, size))
				return (0);
		}
	}
}

int		ft_isplacable(char **map, t_tris tmp)
{
	int	i;
	int	ok;

	i = 0;
	ok = 0;
	while (i < 4)
	{
		ok = (map[tmp.p[i].y][tmp.p[i].x] == '.' ? ok + 1 : 0);
		i++;
	}
	return (ok);
}

int		ft_movet(t_tris *tmp, size_t size)
{
	int i;
	int right;
	int	down;

	i = 0;
	right = 1;
	while (i < 4)
		right = (tmp->p[i++].x + 1 > size ? 0 : right);
	i = 0;
	down = (right == 0 ? 1 : 0);
	while (i < 4)
	{
		if (right)
			tmp->p[i].x++;
		if (down)
		{
			down = (tmp->p[i].y + 1 > size ? 0 : 1);
			tmp->p[i].y = (down ? tmp->p[i].y + 1 : tmp->p[i].y);
			tmp->p[i].x = tmp->p[i].x - size + 1;
		}
		i++;
	}
	return (!down && !right ? 0 : 1);
}

void	ft_tetricpy(t_tris *dst, t_tris src)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		dst->p[i].x = src.p[i].x;
		dst->p[i].y = src.p[i].y;
		dst->name = src.name;
		i++;
	}
}
