/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:39:03 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/26 15:20:55 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_min(t_env *e)
{
	int		tmp;
	int		count;
	int		count_min;
	t_stack	*current;

	tmp = 2147483647;
	count = 1;
	count_min = 1;
	current = e->stack_a;
	while (current != NULL)
	{
		tmp > current->value ? count_min = count : 0;
		tmp > current->value ? tmp = current->value : 0;
		current = current->next;
		count++;
	}
	e->min = tmp;
	e->count_min = count_min;
	count_min > (count / 2) ? e->count_min = ABS((count - count_min + 1)) : 0;
	count /= 2;
	return (count_min > count ? 1 : -1);
}

int		sort(t_env *e)
{
	if (e->stack_a->next == NULL)
		return (0);
	while (check_sorted(e->stack_a, INC) != 0 || e->stack_b == NULL)
	{
		if (e->stack_a == NULL && e->stack_b != NULL &&
			check_sorted(e->stack_b, DEC) == 0)
			break ;
		e->m = get_min(e);
		if (e->min == e->stack_a->next->value)
			move_swap_a(e, ONE);
		else
			while (e->count_min-- - 1 > 0)
				e->m == -1 ? move_rotate_a(e, ONE) : move_reverse_rotate_a(e, ONE);
		if (check_sorted(e->stack_a, INC) == 0 && e->stack_b == NULL)
			break ;
		move_push_b(e);
	}
	while (e->stack_b != NULL)
		move_push_a(e);
	return (0);
}

int		check_sorted(t_stack *stack, int mode)
{
	t_stack	*current;

	current = stack;
	while (current->next != NULL)
	{
		if (mode == INC && current->value > current->next->value)
			return (-1);
		if (mode == DEC && current->value < current->next->value)
			return (-1);
		current = current->next;
	}
	return (0);
}
