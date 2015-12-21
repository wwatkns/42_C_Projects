/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:11:00 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/21 21:41:53 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**ft_read(const char *argv, int *tabwidth)
{
	int		y;
	int		fd;
	char	*line;
	int		**tab;

	y = 0;
	ft_error((fd = open(argv, O_RDONLY)));
	ft_error((int)(tab = (int**)malloc(sizeof(int*) * TAB_SIZE)));
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);

	//	ft_maperror(line);
		*tabwidth = (*tabwidth == 0 ? ft_wordcount(line, ' ') : *tabwidth);
		ft_tabassign(tab, line, *tabwidth, y++);
		free(line);
	}
	return (tab);
}

void	ft_tabassign(int **tab, const char *line, int wc, int y)
{
	int i;
	int x;

	i = 0;
	x = 0;
	ft_error((int)(tab[y] = (int*)malloc(sizeof(int) * wc)));
	while (x < wc)
	{
		if (ft_isdigit(line[i]) || line[i] == '-')
		{
			tab[y][x] = ft_atoi(&line[i]);
			while (ft_isdigit(line[i]) || line[i] == '-')
				i++;
			x++;
		}
		i++;
	}
}

void	ft_maperror(const char *line)
{
	int			n;
	static int	t = 0;

	while (line[n] != '\0')
	{
		ft_error((ft_isdigit(line[n]) || line[n] == ' ' || line[n] == '-'));
		ft_error(!(line[n + 1] != 0 && line[n] == '-' && line[n + 1] == '0'));
		n++;
	}
	ft_error(!(t != 0 && n != t));
	t = n;
}

void	ft_error(int err)
{
	if (err == 0 || err == -1)
	{
		ft_putstr_fd("error\n", 2);
		exit(0);
	}
}
