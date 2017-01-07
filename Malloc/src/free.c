/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:49:37 by wwatkins          #+#    #+#             */
/*   Updated: 2017/01/05 15:44:50 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*g_base;

static int	is_zone_empty(t_zone *current)
{
	size_t	i;
	size_t	num;

	i = -1;
	num = get_info(current->type, NUM);
	while (++i < num)
		if (current->block[i] != 0)
			return (0);
	return (1);
}

static int	deallocate(t_zone *current, t_zone *prev, size_t zone_size)
{
	t_zone	*tmp;

	if (prev)
		prev->next = current->next;
	else
		g_base = current->next;
	tmp = current;
	current = current->next;
	if (munmap(tmp, zone_size) == 0 || !current)
		return (1);
	return (0);
}

void		free(void *ptr)
{
	t_zone	*prev;
	t_zone	*current;
	size_t	zone_size;

	prev = NULL;
	current = g_base;
	while (current)
	{
		if (!(zone_size = get_info(current->type, SIZE)))
			zone_size = convert_to_pagesize(current->block[0] + HEADER_SIZE);
		if (ptr >= (void*)current && ptr < (void*)current + zone_size)
		{
			if (!check_addr(current, ptr))
				return ;
			current->block[get_block_index(current, ptr)] = 0;
			if (current->type == LARGE || is_zone_empty(current))
				if (deallocate(current, prev, zone_size) == 1)
					return ;
		}
		prev = current;
		current = current->next;
	}
}
