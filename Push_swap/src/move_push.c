/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:17:36 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/25 14:16:56 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_push_a(t_env *e)
{
	int		temp;
	t_stack	*new;

	if (e->stack_b != NULL)
	{
		temp = e->stack_b->value;
		e->stack_b = e->stack_b->next;
		error((int)(new = (t_stack*)malloc(sizeof(t_stack))));
		new->value = temp;
		new->next = e->stack_a;
		e->stack_a = new;
		add_move(e, "pa");
	}
}

void	move_push_b(t_env *e)
{
	int		temp;
	t_stack	*new;

	if (e->stack_a != NULL)
	{
		temp = e->stack_a->value;
		e->stack_a = e->stack_a->next;
		error((int)(new = (t_stack*)malloc(sizeof(t_stack))));
		new->value = temp;
		new->next = e->stack_b;
		e->stack_b = new;
		add_move(e, "pb");
	}
}
