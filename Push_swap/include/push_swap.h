/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 10:36:15 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/25 11:55:10 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // temporary

typedef struct	s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_env
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_end_a;
	t_stack	*stack_end_b;
}				t_env;

/*
**	main.c functions
*/

void			check_args(int argc, char **argv);
void			init_stacks(t_env *e);
void			create_stacks(t_env *e, int argc, char **argv);
void			error(int err);

#endif
