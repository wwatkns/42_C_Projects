/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:48:13 by wwatkins          #+#    #+#             */
/*   Updated: 2017/01/07 13:54:49 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*g_base = NULL;

static int		check_size(size_t size)
{
	struct rlimit	rl;

	getrlimit(RLIMIT_DATA, &rl);
	if (size <= 0 || size > rl.rlim_cur)
		return (0);
	return (1);
}

static void		set_blocks(t_zone *zone, size_t size)
{
	size_t	i;
	size_t	num;

	i = -1;
	num = get_info(zone->type, NUM);
	while (++i < num)
		zone->block[i] = 0;
	zone->block[0] = size;
}

static t_zone	*request_zone(t_zone *last, size_t size)
{
	t_zone	*request;
	size_t	zone_size;

	if (!(zone_size = get_info(TYPE(size), SIZE)))
		zone_size = convert_to_pagesize(size + HEADER_SIZE);
	if (!(request = mmap(0, zone_size, MMAP_PROT, MMAP_FLAG, -1, 0)))
		return (NULL);
	request->type = TYPE(size);
	request->next = NULL;
	last ? last->next = request : 0;
	set_blocks(request, size);
	return (request);
}

static void		*find_free_block(t_zone **last, size_t size)
{
	size_t	i;
	size_t	num;
	t_zone	*current;

	current = g_base;
	while (current)
	{
		if (current->type == TYPE(size))
		{
			num = get_info(current->type, NUM);
			i = -1;
			while (++i < num)
				if (current->block[i] == 0)
				{
					current->block[i] = size;
					return (get_block_addr(current, i));
				}
		}
		*last = current;
		current = current->next;
	}
	return (NULL);
}

void			*malloc(size_t size)
{
	t_zone	*zone;
	t_zone	*last;
	void	*addr;

	if (!check_size(size))
		return (NULL);
	if (!g_base)
	{
		if (!(zone = request_zone(NULL, size)))
			return (NULL);
		g_base = zone;
		return (zone + 1);
	}
	last = g_base;
	if (!(addr = find_free_block(&last, size)))
		if (!(zone = request_zone(last, size)))
			return (NULL);
	return (!addr ? zone + 1 : addr);
}
