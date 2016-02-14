/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 11:05:13 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/14 13:02:48 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int argc, char **argv)
{
	t_env	e;

	args_get(&e, argc, argv);
	env_init(&e);
	parse_scene(&e);
	cam_init(&e);
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
	e->arg.s = 0;
	e->arg.g = -1;
	e->arg.f = -1;
	e->arg.m = -1;
	e->arg.x = INFINITY;
	e->arg.y = INFINITY;
	e->arg.z = INFINITY;
	while (++i < argc)
		args_comp(e, argc, argv, i);
	e->arg.w = (e->arg.w < 320 ? 1000 : e->arg.w);
	e->arg.h = (e->arg.h < 200 ? 900 : e->arg.h);
	if (e->arg.s != 1 && e->arg.s != 2 && e->arg.s != 4 && e->arg.s != 8)
		e->arg.s = 1;
}

void	args_comp(t_env *e, int argc, char **argv, int i)
{
	if (i + 1 < argc)
	{
		if (!ft_strcmp(argv[i], "-w") || !ft_strcmp(argv[i], "--width"))
			e->arg.w = ft_atoi(argv[i + 1]);
		if (!ft_strcmp(argv[i], "-h") || !ft_strcmp(argv[i], "--height"))
			e->arg.h = ft_atoi(argv[i + 1]);
		if (!ft_strcmp(argv[i], "-s") || !ft_strcmp(argv[i], "--supersampling"))
			e->arg.s = ft_atoi(argv[i + 1]);
		if (!ft_strcmp(argv[i], "-g") || !ft_strcmp(argv[i], "--gamma"))
			e->arg.g = ft_atof(argv[i + 1]);
		if (!ft_strcmp(argv[i], "-f") || !ft_strcmp(argv[i], "--fov"))
			e->arg.f = ft_atoi(argv[i + 1]);
		if (!ft_strcmp(argv[i], "-m") || !ft_strcmp(argv[i], "--maxdepth"))
			e->arg.m = ft_atoi(argv[i + 1]);
		if (!ft_strcmp(argv[i], "-x"))
			e->arg.x = ft_atof(argv[i + 1]);
		if (!ft_strcmp(argv[i], "-y"))
			e->arg.y = ft_atof(argv[i + 1]);
		if (!ft_strcmp(argv[i], "-z"))
			e->arg.z = ft_atof(argv[i + 1]);
	}
	!ft_strcmp(argv[i], "--help") ? args_disp() : 0;
}

void	args_disp(void)
{
	ft_putendl("\nusage:\n./rtv1 [scene] [-w width] [-h height] [--help]");
	ft_putendl("\noptions:");
	ft_putendl("-w <width>       set specified program window width.");
	ft_putendl("-h <height>      set specified program window height.");
	ft_putendl("-s <sampling>    set specified supersampling value.");
	ft_putendl("-g <gamma>       set specified gamma value.");
	ft_putendl("-f <fov>         set specified fov value.");
	ft_putendl("-m <maxdepth>    set specified max reflection depth value.");
	ft_putendl("-x <angle(deg)>  set specified camera angle on x.");
	ft_putendl("-y <angle(deg)>  set specified camera angle on y.");
	ft_putendl("-z <angle(deg)>  set specified camera angle on z.");
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
