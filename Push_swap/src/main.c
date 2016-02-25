/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 11:04:14 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/25 14:17:45 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_env	e;

	check_args(argc, argv);
	init_stacks(&e);
	create_stacks(&e, argc, argv);

	disp_stack(e.stack_a);
	disp_stack(e.stack_b);
	move_push_b(&e);
	disp_stack(e.stack_a);
	disp_stack(e.stack_b);

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

void	init_stacks(t_env *e)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	error((int)(stack_a = (t_stack*)malloc(sizeof(t_stack))));
	error((int)(stack_b = (t_stack*)malloc(sizeof(t_stack))));
	e->stack_a = stack_a;
	e->stack_b = stack_b;
	e->stack_a->next = NULL;
	e->stack_b->next = NULL;
}

void	create_stacks(t_env *e, int argc, char **argv)
{
	int		i;
	t_stack	*new;
	t_stack	*head;
	t_stack	*current;

	i = 0;
	head = e->stack_a;
	current = head;
	while (++i < argc)
	{
		current->value = ft_atoi(argv[i]);
		if (i + 1 < argc)
		{
			error((int)(new = (t_stack*)malloc(sizeof(t_stack))));
			current->next = new;
			current = current->next;
		}
	}
	current->next = NULL;
	e->stack_end_a = current;
	e->stack_a = head;
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
