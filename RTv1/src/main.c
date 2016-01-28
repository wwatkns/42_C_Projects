/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 11:05:13 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/28 16:45:25 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int argc, char **argv)
{
	t_env	e;

	args_get(&e, argc, argv);
	parse_scene(&e);
	core(&e);
	return (0);
}

void	args_get(t_env *e, int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 1)
		e->arg.file_scene = ft_strdup("resource/scene/default.scene");
	else
		e->arg.file_scene = ft_strdup(argv[1]);
	e->arg.w = 0;
	e->arg.h = 0;
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "-w") && i + 1 < argc)
			e->arg.w = ft_atoi(argv[i + 1]);
		if (!ft_strcmp(argv[i], "-h") && i + 1 < argc)
			e->arg.h = ft_atoi(argv[i + 1]);
		!ft_strcmp(argv[i], "--help") ? args_disp() : 0;
	}
	e->arg.w = (e->arg.w < 320 || e->arg.w > 2560 ? 1000 : e->arg.w);
	e->arg.h = (e->arg.h < 200 || e->arg.h > 1440 ? 720 : e->arg.h);
}

void	args_disp(void)
{
	ft_putendl("\nusage:\n./rtv1 [scene] [-w width] [-h height] [--help]");
	ft_putendl("\noptions");
	ft_putendl("-w <width>	set specified program window width.");
	ft_putendl("-h <height>	set specified program window height.");
	ft_putendl("--help		show help.\n");
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
