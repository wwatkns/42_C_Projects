/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:49:22 by wwatkins          #+#    #+#             */
/*   Updated: 2017/01/05 15:44:41 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*g_base;

static t_zone	*find_zone_from_addr(void *ptr)
{
	t_zone	*current;
	size_t	zone_size;

	current = g_base;
	while (current)
	{
		if (!(zone_size = get_info(current->type, SIZE)))
			zone_size = convert_to_pagesize(current->block[0] + HEADER_SIZE);
		if (ptr >= (void*)current && ptr < (void*)current + zone_size)
			return (current);
		current = current->next;
	}
	return (NULL);
}

static void		*change_allocation_size(t_zone *zone, void *ptr, size_t size)
{
	size_t	index;

	index = get_block_index(zone, ptr);
	zone->block[index] = size;
	return (ptr);
}

void			*realloc(void *ptr, size_t size)
{
	t_zone	*current;
	size_t	block_size;
	void	*addr;

	if (ptr == NULL)
		return (malloc(size));
	if ((current = find_zone_from_addr(ptr)))
	{
		if (!check_addr(current, ptr))
			return (NULL);
		block_size = current->block[get_block_index(current, ptr)];
		if (size == 0)
			addr = malloc(1);
		else if (size <= get_info(current->type, RES))
			return (change_allocation_size(current, ptr, size));
		else
		{
			addr = malloc(size);
			ft_memcpy(addr, ptr, get_info(current->type, RES));
		}
		free(ptr);
		return (addr);
	}
	return (NULL);
}
