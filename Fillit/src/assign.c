/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:18:14 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/11 16:24:59 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tris	*ft_assign(char *buf)
{
	int		i;
	int		n;
	t_tris	*assign;

	i = 0;
	n = 0;
	ft_error((int)(assign = (t_tris*)malloc(sizeof(t_tris) * 26)));
	while (buf[i] != '\0')
	{
		ft_assigncoor(assign, buf, &i, n);
		ft_relcoor(&assign[n]);
		n++;
		i++;
	}
	return (assign);
}

void	ft_assigncoor(t_tris *assign, char *buf, int *i, int n)
{
	int x;
	int y;
	int j;

	y = 0;
	j = 0;
	while (y++ < 4)
	{
		x = 0;
		while (x++ < 4)
		{
			if (buf[*i] == '#')
			{
				assign[n].p[j].x = x;
				assign[n].p[j].y = y;
				assign[n].name = 'A' + (*i / 21);
				j++;
			}
			*i += 1;
		}
		*i += 1;
	}
}

void	ft_relcoor(t_tris *assign)
{
	int i;
	int xmin;
	int ymin;

	i = 0;
	xmin = assign->p[0].x;
	ymin = assign->p[0].y;
	while (i < 4)
	{
		xmin = (assign->p[i].x < xmin ? assign->p[i].x : xmin);
		ymin = (assign->p[i].y < ymin ? assign->p[i].y : ymin);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		assign->p[i].x -= xmin;
		assign->p[i].y -= ymin;
		i++;
	}
}
