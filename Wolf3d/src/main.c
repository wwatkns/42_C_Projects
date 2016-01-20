/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:01:11 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/20 14:19:42 by wwatkins         ###   ########.fr       */
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
	argc > 6 ? args_disp() : 0;
	if (argc == 1 || !ft_strstr(argv[1], ".map"))
		e->arg.map = ft_strdup("maps/default.map");
	else
		e->arg.map = ft_strdup(argv[1]);
	e->arg.w = 0;
	e->arg.h = 0;
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "-w") && i + 1 < argc)
			e->arg.w = ft_atoi(argv[i + 1]);
		if (!ft_strcmp(argv[i], "-h") && i + 1 < argc)
			e->arg.h = ft_atoi(argv[i + 1]);
	}
	e->arg.w = (e->arg.w < 320 || e->arg.w > 2560 ? 960 : e->arg.w);
	e->arg.h = (e->arg.h < 200 || e->arg.h > 1440 ? 960 : e->arg.h);
}

void	args_disp(void)
{
	ft_putendl("\nusage: ./wolf3d (maps) [-w width] [-h height]");
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
