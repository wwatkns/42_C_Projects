/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:17:36 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/25 15:32:15 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_push_a(t_env *e)
{
	t_stack	*temp;

	if (e->stack_b != NULL)
	{
		temp = e->stack_b;
		e->stack_b = e->stack_b->next;
		temp->next = e->stack_a;
		e->stack_a = temp;
		e->stack_a->next == NULL ? e->stack_end_a = e->stack_a : 0;
		e->stack_b == NULL ? e->stack_end_b = NULL : 0;
		add_move(e, "pa");
	}
}

void	move_push_b(t_env *e)
{
	t_stack	*temp;

	if (e->stack_a != NULL)
	{
		temp = e->stack_a;
		e->stack_a = e->stack_a->next;
		temp->next = e->stack_b;
		e->stack_b = temp;
		e->stack_b->next == NULL ? e->stack_end_b = e->stack_b : 0;
		e->stack_a == NULL ? e->stack_end_a = NULL : 0;
		add_move(e, "pb");
	}
}
