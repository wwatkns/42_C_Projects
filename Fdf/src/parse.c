/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 11:41:32 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/08 13:51:53 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**ft_parse(t_env *e)
{
	int		fd;
	char	*line;
	int		**tab;
	int		j;

	j = 0;
	line = ft_strnew(1);
	ft_getgridsize(e);
	ft_error((fd = open(e->arg.map, O_RDWR)));
	ft_error((int)(tab = (int**)malloc(sizeof(int*) * (e->gh + 1))));
	e->minh = 0;
	e->maxh = 0;
	while (get_next_line(fd, &line))
	{
		ft_maperror(line);
		ft_tabassign(e, tab, line, j);
		free(line);
		j++;
	}
	ft_error((j));
	ft_error((close(fd) + 1));
	return (tab);
}

void	ft_getgridsize(t_env *e)
{
	int		fd;
	char	*line;

	e->gh = 0;
	ft_error((fd = open(e->arg.map, O_RDWR)));
	get_next_line(fd, &line);
	e->gw = ft_wordcount(line, ' ');
	e->gh++;
	while (get_next_line(fd, &line))
		e->gh++;
	free(line);
}

void	ft_tabassign(t_env *e, int **tab, const char *line, int j)
{
	int		i;
	int		x;
	char	**split;

	i = 0;
	x = 0;
	ft_error((int)(tab[j] = (int*)malloc(sizeof(int) * (e->gw + 1))));
	split = ft_strsplit(line, ' ');
	while (split[i] != NULL)
	{
		tab[j][i] = ft_atoi(split[i]);
		e->minh = (tab[j][i] < e->minh ? tab[j][i] : e->minh);
		e->maxh = (tab[j][i] > e->maxh ? tab[j][i] : e->maxh);
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_maperror(const char *line)
{
	int			i;

	i = 0;
	while (line[i] != '\0')
	{
		ft_error((ft_isalnum(line[i]) || line[i] == ' ' ||
					line[i] == ',') || line[i] == '-');
		i++;
	}
}

void	ft_error(int err)
{
	if (err == 0 || err == -1)
	{
		ft_putstr_fd("error\n", 2);
		exit(0);
	}
}
