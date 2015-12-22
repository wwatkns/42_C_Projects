/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:11:00 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/22 16:56:21 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**ft_read(t_env *e, const char *argv)
{
	int		fd;
	char	*line;
	int		**tab;

	ft_error((fd = open(argv, O_RDONLY)));
	ft_error((int)(tab = (int**)malloc(sizeof(int*) * TAB_SIZE)));
	get_next_line(fd, &line);
	e->gh = 0;
	e->gw = ft_wordcount(line, ' ');
	ft_tabassign(*e, tab, line);
	e->gh++;
	while (get_next_line(fd, &line))
	{
		ft_tabassign(*e, tab, line);
		free(line);
		e->gh++;
	}
	return (tab);
}

void	ft_tabassign(t_env e, int **tab, const char *line)
{
	int i;
	int x;

	i = 0;
	x = 0;
	ft_error((int)(tab[e.gh] = (int*)malloc(sizeof(int) * e.gw)));
	while (x < e.gw)
	{
		if (ft_isdigit(line[i]) || line[i] == '-')
		{
			tab[e.gh][x] = ft_atoi(&line[i]);
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
