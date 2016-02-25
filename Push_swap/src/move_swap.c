/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:01:32 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/25 16:10:15 by wwatkins         ###   ########.fr       */
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
	int	c;

	c = 0;
	c += move_swap_a(e, BOTH);
	c += move_swap_b(e, BOTH);
	c != 0 ? add_move(e, "ss") : 0;
}
