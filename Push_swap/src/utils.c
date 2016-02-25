/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:15:50 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/25 14:00:33 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_move(t_env *e, const char *move)
{
	(void)e;
	ft_putstr(move);
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
			printf("[%d], ", current->value);
		else
			printf("[%d]", current->value);
		current = current->next;
	}
	printf(")\n");
}
