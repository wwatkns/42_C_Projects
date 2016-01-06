/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:27:53 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/06 10:31:04 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_env	e;
	int		**tab;

	ft_getargs(&e, argc, argv);
	tab = ft_parse(&e);
	ft_core(&e, tab);
	ft_cleanall(&e, tab);
	return (0);
}

void	ft_getargs(t_env *e, int argc, char **argv)
{
	int i;

	i = 1;
	ft_error((argc >= 2 && argc <= 8));
	e->arg.map = ft_strdup(argv[1]);
	e->arg.pal = NULL;
	e->arg.w = 0;
	e->arg.h = 0;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-p") && i + 1 < argc)
			e->arg.pal = ft_strdup(argv[i + 1]);
		else if (!ft_strcmp(argv[i], "-w") && i + 1 < argc)
			e->arg.w = ft_atoi(argv[i + 1]);
		else if (!ft_strcmp(argv[i], "-h") && i + 1 < argc)
			e->arg.h = ft_atoi(argv[i + 1]);
		i++;
	}
	e->arg.w = (e->arg.w <= 0 || e->arg.w > 2560 ? 1200 : e->arg.w);
	e->arg.h = (e->arg.h <= 0 || e->arg.h > 1440 ? 1200 : e->arg.h);
	e->arg.pal == NULL ? e->arg.pal = ft_strdup("palette/default.fdfcolor") : 0;
}

void	ft_cleanall(t_env *e, int **tab)
{
	int	i;

	i = 0;
	while (i < e->gw)
	{
		free(e->pts[i]);
		free(tab[i]);
		i++;
	}
	free(e->pts);
	free(tab);
	free(e->arg.map);
	free(e->arg.pal);
	free(e->img.adr);
	free(e->img.img);
	free(e->mlx);
	free(e->win);
	free(e);
}
