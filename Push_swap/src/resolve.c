/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:39:03 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/25 17:53:08 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		resolve(t_env *e)
{
	(void)e;
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
