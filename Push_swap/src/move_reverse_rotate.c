/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:10:54 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/25 16:38:40 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		move_reverse_rotate_a(t_env *e, int move)
{
	t_stack	*tmp;
	t_stack	*tmp_end;

	if (e->stack_a != NULL && e->stack_a->next != NULL)
	{
		tmp = e->stack_a;
		tmp_end = e->stack_end_a;
		while (tmp->next != e->stack_end_a)
			tmp = tmp->next;
		e->stack_end_a = tmp;
		e->stack_end_a->next = NULL;
		tmp_end->next = e->stack_a;
		e->stack_a = tmp_end;
		move == ONE ? add_move(e, "rra") : 0;
		return (1);
	}
	return (0);
}

int		move_reverse_rotate_b(t_env *e, int move)
{
	t_stack	*tmp;
	t_stack	*tmp_end;

	if (e->stack_b != NULL && e->stack_b->next != NULL)
	{
		tmp = e->stack_b;
		tmp_end = e->stack_end_b;
		while (tmp->next != e->stack_end_b)
			tmp = tmp->next;
		e->stack_end_b = tmp;
		e->stack_end_b->next = NULL;
		tmp_end->next = e->stack_b;
		e->stack_b = tmp_end;
		move == ONE ? add_move(e, "rrb") : 0;
		return (1);
	}
	return (0);
}

void	move_reverse_rotate_both(t_env *e)
{
	int	c;

	c = 0;
	c += move_reverse_rotate_a(e, BOTH);
	c += move_reverse_rotate_b(e, BOTH);
	c != 0 ? add_move(e, "rrr") : 0;
}
