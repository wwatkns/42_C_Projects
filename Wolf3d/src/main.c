/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:01:11 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/18 12:45:30 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int argc, char **argv)
{
	t_env e;

	ft_getargs(&e, argc, argv);
	ft_core(&e);
	return (0);
}

void	ft_getargs(t_env *e, int argc, char **argv)
{
	int	i;

	i = 0;
	argc > 5 ? ft_dispargs() : 0;
	e->arg.w = 0;
	e->arg.h = 0;
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "-w") && i + 1 < argc)
			e->arg.w = ft_atoi(argv[i + 1]);
		if (!ft_strcmp(argv[i], "-h") && i + 1 < argc)
			e->arg.h = ft_atoi(argv[i + 1]);
	}
	e->arg.w = (e->arg.w < 420 || e->arg.w > 2560 ? 800 : e->arg.w);
	e->arg.h = (e->arg.h < 420 || e->arg.h > 1440 ? 800 : e->arg.h);
}

void	ft_dispargs(void)
{
	ft_putendl("\nusage: ./wolf3d [-w width] [-h height]");
	exit(0);
}

void	ft_error(int err)
{
	if (err == 0 || err == -1)
	{
		ft_putendl_fd("error", 2);
		exit(0);
	}
}
