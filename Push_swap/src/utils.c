/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:15:50 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/26 15:30:34 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_move(t_env *e, char *move)
{
	if (e->move == NULL)
	{
		error((int)(e->move = (t_move*)malloc(sizeof(t_move))));
		e->move_end = e->move;
		e->count = 1;
	}
	else
	{
		error((int)(e->move_end->next = (t_move*)malloc(sizeof(t_move))));
		e->move_end = e->move_end->next;
		e->count++;
	}
	disp_stack(e->stack_a);
	disp_stack(e->stack_b);
	e->move_end->name = move;
	e->move_end->next = NULL;
}

void	disp_moves(t_env *e)
{
	t_move	*current;

	current = e->move;
	while (current != NULL)
	{
		ft_putstr(current->name);
		current->next != NULL ? ft_putchar(' ') : 0;
		current = current->next;
	}
	ft_putchar('\n');
}

void	disp_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	printf("(");
	while (current != NULL)
	{
		if (current->next != NULL)
			printf("%d, ", current->value);
		else
			printf("%d", current->value);
		current = current->next;
	}
	printf(")\n");
}
