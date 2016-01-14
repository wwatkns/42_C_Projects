/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:27:53 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/11 10:34:31 by wwatkins         ###   ########.fr       */
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
	ft_cleanall(&e);
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
		else if (!ft_strcmp(argv[i], "--help"))
			ft_helparg();
		i++;
	}
	e->arg.w = (e->arg.w < 420 || e->arg.w > 2560 ? 1280 : e->arg.w);
	e->arg.h = (e->arg.h < 420 || e->arg.h > 1440 ? 1000 : e->arg.h);
	e->arg.pal == NULL ? e->arg.pal = ft_strdup("palette/default.fdfcolor") : 0;
}

void	ft_initimg(t_env *e)
{
	ft_error((int)(e->img.adr = mlx_new_image(e->mlx, e->scw, e->sch)));
	e->img.img = mlx_get_data_addr(e->img.adr, &e->img.bpp,
	&e->img.sl, &e->img.endian);
}

void	ft_helparg(void)
{
	ft_putendl("usage: ./fdf map.fdf [-p palette] [-w width] [-h height]");
	ft_putendl("\noptions: -p load palette from .fdfcolor file");
	ft_putendl("         -w specify window width");
	ft_putendl("         -h specify window height");
	ft_putendl("         --help show help");
	exit(0);
}

void	ft_cleanall(t_env *e)
{
	int i;

	i = -1;
	while (++i < e->gw)
		ft_memdel((void**)e->pts[i]);
	ft_memdel((void**)e->pts);
	ft_memdel((void**)e->arg.map);
	ft_memdel((void**)e->arg.pal);
	ft_memdel((void**)e->img.adr);
	ft_memdel((void**)e->img.img);
	ft_memdel((void**)e->mlx);
	ft_memdel((void**)e->win);
	ft_memdel((void**)e);
}
