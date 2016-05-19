/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:01:11 by wwatkins          #+#    #+#             */
/*   Updated: 2016/03/19 11:49:44 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int argc, char **argv)
{
	t_env e;

	args_get(&e, argc, argv);
	core(&e);
	return (0);
}

void	args_get(t_env *e, int argc, char **argv)
{
	int	i;

	i = 0;
	e->arg.file_map = NULL;
	e->arg.file_template = NULL;
	e->arg.texture = 0;
	e->arg.w = 0;
	e->arg.h = 0;
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "-m") && i + 1 < argc)
			e->arg.file_map = ft_strdup(argv[i + 1]);
		if (!ft_strcmp(argv[i], "-t") && i + 1 < argc)
			e->arg.file_template = ft_strdup(argv[i + 1]);
		if (!ft_strcmp(argv[i], "-w") && i + 1 < argc)
			e->arg.w = ft_atoi(argv[i + 1]);
		if (!ft_strcmp(argv[i], "-h") && i + 1 < argc)
			e->arg.h = ft_atoi(argv[i + 1]);
		!ft_strcmp(argv[i], "--help") ? args_disp() : 0;
	}
	if (e->arg.file_map == NULL)
		e->arg.file_map = ft_strdup("resource/map/default.map");
	e->arg.file_template != NULL ? e->arg.texture = 1 : 0;
	e->arg.w = (e->arg.w < 320 || e->arg.w > 2560 ? 1000 : e->arg.w);
	e->arg.h = (e->arg.h < 200 || e->arg.h > 1440 ? 720 : e->arg.h);
}

void	args_disp(void)
{
	ft_putstr("\nusage:\n./wolf3d [-m map_file] [-t template_file] ");
	ft_putendl("[-w width] [-h height] [--help]");
	ft_putendl("\noptions:");
	ft_putendl("-m <file_path> loads specified map file.");
	ft_putstr("-t <file_path> loads specified template file, which contains");
	ft_putendl(" path to textures.");
	ft_putendl("-w <width>     set specified program window width.");
	ft_putendl("-h <height>    set specified program window height.");
	ft_putendl("--help         show help.\n");
	exit(0);
}

void	error(int err)
{
	if (err == 0 || err == -1)
	{
		ft_putendl_fd("error", 2);
		exit(0);
	}
}
