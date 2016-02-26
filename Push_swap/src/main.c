/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 11:04:14 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/26 10:29:16 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_env	e;

	check_args(argc, argv);
	create_stacks(&e, argc, argv);

/*	disp_stack(e.stack_a);
	disp_stack(e.stack_b);
	move_push_b(&e);
	disp_stack(e.stack_a);
	disp_stack(e.stack_b);
	move_push_b(&e);
	disp_stack(e.stack_a);
	disp_stack(e.stack_b);
	move_rotate_a(&e, ONE);
	disp_stack(e.stack_a);
	disp_stack(e.stack_b);
	move_reverse_rotate_both(&e);
	disp_stack(e.stack_a);
	disp_stack(e.stack_b);

//	printf("%d\n", check_sorted(e.stack_a, DEC));

	disp_moves(&e);*/
	resolve(&e);
	return (0);
}

void	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
			error(!(ft_strcmp(argv[j], argv[i]) == 0));
	}
}

void	create_stacks(t_env *e, int argc, char **argv)
{
	int		i;
	t_stack	*current;

	i = 0;
	e->move = NULL;
	e->stack_b = NULL;
	error((int)(current = (t_stack*)malloc(sizeof(t_stack))));
	e->stack_a = current;
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
		ft_putstr("error\n");
		exit(0);
	}
	return ;
}
