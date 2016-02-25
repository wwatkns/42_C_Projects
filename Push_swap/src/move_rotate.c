/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:17:57 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/25 16:39:09 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		move_rotate_a(t_env *e, int move)
{
	t_stack	*tmp;

	if (e->stack_a != NULL && e->stack_a->next != NULL)
	{
		tmp = e->stack_a;
		e->stack_a = e->stack_a->next;
		tmp->next = NULL;
		e->stack_end_a->next = tmp;
		e->stack_end_a = tmp;
		move == ONE ? add_move(e, "ra") : 0;
		return (1);
	}
	return (0);
}

int		move_rotate_b(t_env *e, int move)
{
	t_stack	*tmp;

	if (e->stack_b != NULL && e->stack_a->next != NULL)
	{
		tmp = e->stack_b;
		e->stack_b = e->stack_b->next;
		tmp->next = NULL;
		e->stack_end_b->next = tmp;
		e->stack_end_b = tmp;
		move == ONE ? add_move(e, "rb") : 0;
		return (1);
	}
	return (0);
}

void	move_rotate_both(t_env *e)
{
	int	c;

	c = 0;
	c += move_rotate_a(e, BOTH);
	c += move_rotate_b(e, BOTH);
	c != 0 ? add_move(e, "rr") : 0;
}
