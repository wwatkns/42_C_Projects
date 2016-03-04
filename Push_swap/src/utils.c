/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:15:50 by wwatkins          #+#    #+#             */
/*   Updated: 2016/03/04 15:53:30 by wwatkins         ###   ########.fr       */
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
	e->move_end->name = move;
	e->move_end->next = NULL;
	if (e->arg.verbose)
	{
		disp_stack(e, e->stack_a, 'a');
		disp_stack(e, e->stack_b, 'b');
		ft_putstr("> ");
		ft_putstr(move);
		ft_putchar('\n');
	}
}

void	disp_moves(t_env *e)
{
	t_move	*current;

	current = e->move;
	while (current != NULL)
	{
		e->arg.color ? set_color(current->name) : 0;
		ft_putstr(current->name);
		current->next != NULL ? ft_putchar(' ') : 0;
		current = current->next;
		ft_putstr(COLOR_END);
	}
	ft_putchar('\n');
}

void	disp_stack(t_env *e, t_stack *stack, char n)
{
	t_stack	*current;

	current = stack;
	n == 'a' && e->arg.color ? ft_putstr(COLOR_GREEN) : 0;
	n == 'b' && e->arg.color ? ft_putstr(COLOR_GREY) : 0;
	ft_putchar(n - 32);
	ft_putstr(": (");
	while (current != NULL)
	{
		ft_putnbr(current->value);
		current->next != NULL ? ft_putstr(", ") : 0;
		current = current->next;
	}
	ft_putstr(")\n");
	ft_putstr(COLOR_END);
}

void	set_color(char *name)
{
	!ft_strcmp(name, "sa") ? ft_putstr(COLOR_RED) : 0;
	!ft_strcmp(name, "sb") ? ft_putstr(COLOR_GREEN) : 0;
	!ft_strcmp(name, "pa") ? ft_putstr(COLOR_YELLOW) : 0;
	!ft_strcmp(name, "pb") ? ft_putstr(COLOR_BLUE) : 0;
	!ft_strcmp(name, "ra") ? ft_putstr(COLOR_MAGENTA) : 0;
	!ft_strcmp(name, "rb") ? ft_putstr(COLOR_CYAN) : 0;
	!ft_strcmp(name, "rra") ? ft_putstr(COLOR_ORANGE) : 0;
	!ft_strcmp(name, "rrb") ? ft_putstr(COLOR_GREY) : 0;
}
