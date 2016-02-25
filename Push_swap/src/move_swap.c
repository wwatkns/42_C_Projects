/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:01:32 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/25 13:56:06 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		move_swap_a(t_env *e, int move)
{
	int	temp;

	if (e->stack_a != NULL && e->stack_a->next != NULL)
	{
		temp = e->stack_a->value;
		e->stack_a->value = e->stack_a->next->value;
		e->stack_a->next->value = temp;
		move == ONE ? add_move(e, "sb") : 0;
		return (1);
	}
	return (0);
}

int		move_swap_b(t_env *e, int move)
{
	int	temp;

	if (e->stack_b != NULL && e->stack_b->next != NULL)
	{
		temp = e->stack_b->value;
		e->stack_b->value = e->stack_b->next->value;
		e->stack_b->next->value = temp;
		move == ONE ? add_move(e, "sb") : 0;
		return (1);
	}
	return (0);
}

void	move_swap_both(t_env *e)
{
	if (move_swap_a(e, BOTH) || move_swap_b(e, BOTH))
		add_move(e, "ss");
}
