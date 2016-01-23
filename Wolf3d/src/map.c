/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 09:34:44 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/23 13:18:00 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	map_init(t_env *e)
{
	e->map.size = 64;
	map_parse(e);
/*	e->tex.texture = (char**)malloc(sizeof(char*) * 10);
	if (e->arg.texture)
	{
		printf("%s\n", e->arg.file_texture);
		e->img.adr = mlx_xpm_file_to_image(e->mlx, e->arg.file_texture,
		&e->tex.w, &e->tex.h);
		e->img.img = mlx_get_data_addr(e->img.adr, &e->img.bpp,
		&e->img.sl, &e->img.endian);
		printf("%s\n", e->img.img);
	}*/
}

void	map_parse(t_env *e)
{
	int		j;
	int		fd;
	char	*line;

	j = 0;
	error((fd = open(e->arg.file_map, O_RDWR)));
	get_next_line(fd, &line);
	e->map.w = ft_atoi(line);
	get_next_line(fd, &line);
	e->map.h = ft_atoi(line);
	error((int)(e->map.map = (int**)malloc(sizeof(int*) * e->map.h)));
	while (get_next_line(fd, &line))
	{
		map_assign(e, line, j);
		free(line);
		j++;
	}
	error((close(fd) + 1));
}

void	map_assign(t_env *e, const char *line, int j)
{
	int		i;
	char	**split;

	i = 0;
	error((int)(e->map.map[j] = (int*)malloc(sizeof(int) * e->map.w)));
	split = ft_strsplit(line, ' ');
	while (split[i] != NULL)
	{
		e->map.map[j][i] = ft_atoi(split[i]);
		free(split[i]);
		i++;
	}
	free(split);
}
