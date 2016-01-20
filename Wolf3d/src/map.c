/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 09:34:44 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/20 11:34:12 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_map(t_env *e)
{
	e->map.size = 64;
	e->map.w = 15;
	e->map.h = 15;
	parse_map(e);
}

void	parse_map(t_env *e)
{
	int		j;
	int		fd;
	char	*line;

	j = 0;
	ft_error((fd = open(e->arg.map, O_RDWR)));
	get_next_line(fd, &line);
	e->map.w = ft_atoi(line);
	get_next_line(fd, &line);
	e->map.h = ft_atoi(line);
	ft_error((int)(e->map.map = (int**)malloc(sizeof(int*) * e->map.h)));
	while (get_next_line(fd, &line))
	{
		map_assign(e, line, j);
		free(line);
		j++;
	}
	ft_error((close(fd) + 1));
}

void	map_assign(t_env *e, const char *line, int j)
{
	int		i;
	char	**split;

	i = -1;
	split = ft_strsplit(line, ' ');
	while (split[++i] != NULL)
	{
		ft_error((int)(e->map.map[j] = (int*)malloc(sizeof(int) * e->map.w)));
		printf("%s ", split[i]);
		e->map.map[j][i] = ft_atoi(split[i]);
		free(split[i]);
	}
	printf("\n");
	free(split);
}
