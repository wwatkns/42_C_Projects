/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 09:34:44 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/26 08:54:02 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	map_init(t_env *e)
{
	map_parse(e);
	while (e->map.map[(int)e->map.pos.y][(int)e->map.pos.x] != 0)
	{
		e->map.pos.x += 1;
		if (e->map.pos.x > e->map.w && (e->map.pos.y++))
			e->map.pos.x = 0;
		error(!(e->map.pos.y > e->map.h - 1));
	}
	e->map.pos = vec2_add(e->map.pos, vec2(0.5, 0.5));
}

void	texture_init(t_env *e)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	error((fd = open(e->arg.file_template, O_RDWR)));
	get_next_line(fd, &line);
	e->tex.nb = ft_atoi(line);
	error((int)(e->tin = (t_tin*)malloc(sizeof(t_tin) * e->tex.nb)));
	while (get_next_line(fd, &line) > 0)
	{
		ft_strstr(line, "w:") ? e->tin[i].id = 0 : 0;
		ft_strstr(line, "f:") ? e->tex.f = i : 0;
		ft_strstr(line, "c:") ? e->tex.c = i : 0;
		e->tin[i].adr = mlx_xpm_file_to_image(e->mlx, &line[3],
						&e->tin[i].w, &e->tin[i].h);
		e->tin[i].img = mlx_get_data_addr(e->tin[i].adr, &e->tin[i].bpp,
						&e->tin[i].sl, &e->tin[i].endian);
		e->tin[i].opp = e->tin[i].bpp / 8;
		ft_strdel(&line);
		i++;
	}
	ft_strdel(&line);
	error((close(fd) + 1));
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
