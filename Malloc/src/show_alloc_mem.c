/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 12:14:39 by wwatkins          #+#    #+#             */
/*   Updated: 2017/01/05 17:08:29 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*g_base;

void	show_alloc_mem(void)
{
	t_zone	*current;
	size_t	num;
	size_t	total;
	size_t	i;

	total = 0;
	current = g_base;
	while (current)
	{
		ft_printf("%s : %p\n", PTYP(current->type), current);
		num = get_info(current->type, NUM);
		i = -1;
		while (++i < num)
			if (current->block[i] > 0)
			{
				ft_printf("%p - %p : %zu octets\n",
					get_block_addr(current, i),
					get_block_addr(current, i) + current->block[i],
					current->block[i]);
				total += current->block[i];
			}
		current = current->next;
	}
	ft_printf("Total : %zu octets\n", total);
}
