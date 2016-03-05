/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 11:04:14 by wwatkins          #+#    #+#             */
/*   Updated: 2016/03/05 12:15:34 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_env	e;

	if (argc == 1)
		return (0);
	check_args(&e, argc, argv);
	create_stacks(&e, argc, argv);
	sort(&e);
	disp_moves(&e);
	return (0);
}

void	check_args(t_env *e, int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	double	val;

	i = 0;
	j = 0;
	e->arg.verbose = 0;
	e->arg.color = 0;
	while (++j <= 2 && j < argc)
	{
		!ft_strcmp(argv[j], "-v") && (e->arg.verbose = 1) ? i++ : 0;
		!ft_strcmp(argv[j], "-c") && (e->arg.color = 1) ? i++ : 0;
	}
	while (++i < argc)
	{
		k = -1;
		while (argv[i][++k])
			error(!(!ft_isdigit(argv[i][k]) && argv[i][k] != '-'));
		j = i;
		val = ft_atof(argv[i]);
		while (++j < argc)
			error(!(val == ft_atof(argv[j])));
		error(!(val > MAX_INT || val < MIN_INT));
	}
}

void	create_stacks(t_env *e, int argc, char **argv)
{
	int		i;
	t_stack	*current;

	e->move = NULL;
	e->stack_b = NULL;
	error((int)(current = (t_stack*)malloc(sizeof(t_stack))));
	e->stack_a = current;
	i = e->arg.verbose + e->arg.color;
	error(!(i >= argc - 1));
	while (++i < argc)
	{
		current->value = ft_atoi(argv[i]);
		current->next = NULL;
		if (i + 1 < argc)
		{
			error((int)(current->next = (t_stack*)malloc(sizeof(t_stack))));
			current = current->next;
		}
	}
	e->stack_end_a = current;
}

void	error(int err)
{
	if (err == 0 || err == -1)
	{
		ft_putstr("Error\n");
		exit(0);
	}
	return ;
}
