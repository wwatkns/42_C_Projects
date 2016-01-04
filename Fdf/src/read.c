/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:11:00 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/04 20:05:14 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**ft_read(t_env *e, const char *argv)
{
	int		fd;
	char	*line;
	int		**tab;
	int		j;

	j = 0;
	line = ft_strnew(1);
	ft_getgridsize(e, argv);
	ft_error((fd = open(argv, O_RDONLY)));
	ft_error((int)(tab = (int**)malloc(sizeof(int*) * e->gh + 1)));
	e->minh = 0;
	e->maxh = 0;
	while (get_next_line(fd, &line))
	{
		ft_tabassign(e, tab, line, j);
		free(line);
		j++;
	}
	ft_error((close(fd) + 1));
	return (tab);
}

void	ft_getgridsize(t_env *e, const char *argv)
{
	int		fd;
	int		ret;
	char	*buf;
	char	*line;

	ft_error((fd = open(argv, O_RDONLY)));
	ft_error((int)(buf = ft_strnew(BUFFSIZE)));
	ft_error(!(get_next_line(fd, &line) == -1));
	e->gh = 0;
	e->gw = ft_wordcount(line, ' ');
	while ((ret = read(fd, buf, BUFFSIZE)) > 0)
	{
		buf[ret] = 0;
		ft_strchr(buf, '\n') ? e->gh++ : 0;
	}
	ft_error(!(ret == -1));
	e->gh++;
	printf("(%d, %d)\n", e->gw, e->gh);
	free(buf);
	free(line);
}

void	ft_tabassign(t_env *e, int **tab, const char *line, int j)
{
	int i;
	int x;

	i = 0;
	x = 0;
	ft_error((int)(tab[j] = (int*)malloc(sizeof(int) * e->gw + 1)));
	while (x < e->gw)
	{
		if (ft_isdigit(line[i]) || line[i] == '-')
		{
			tab[j][x] = ft_atoi(&line[i]);
			e->minh = (tab[j][x] < e->minh ? tab[j][x] : e->minh);
			e->maxh = (tab[j][x] > e->maxh ? tab[j][x] : e->maxh);
			while (line[i] != ' ')
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

	n = 0;
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
