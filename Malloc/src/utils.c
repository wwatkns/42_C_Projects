/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:03:53 by wwatkins          #+#    #+#             */
/*   Updated: 2017/01/05 17:09:33 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
**	Converts a given size_t variable in a multiple of pagesize.
*/

size_t	convert_to_pagesize(size_t x)
{
	size_t	pagesize;

	pagesize = getpagesize();
	return ((x + pagesize - 1) / pagesize * pagesize);
}

/*
**	Check if the ptr is a multiple of the zone res and if the block is
**	allocated.
*/

int		check_addr(t_zone *zone, void *ptr)
{
	size_t	mod;

	mod = (ptr - ((void*)zone + HEADER_SIZE)) % get_info(zone->type, RES);
	return (mod == 0 && zone->block[get_block_index(zone, ptr)] != 0 ? 1 : 0);
}

/*
**	Returns the block index given a zone and the address of the block.
*/

size_t	get_block_index(t_zone *zone, void *ptr)
{
	return ((ptr - ((void*)zone + HEADER_SIZE)) / get_info(zone->type, RES));
}

/*
**	Returns the block address given a zone and the index of the block.
*/

void	*get_block_addr(t_zone *zone, size_t index)
{
	return ((void*)(zone + 1) + index * get_info(zone->type, RES));
}

/*
**	Returns requested info (NUM, RES, SIZE) given the zone type.
*/

size_t	get_info(size_t type, int info)
{
	const size_t	num[3] = {BNUM, BNUM, 1};
	const size_t	res[3] = {TINY_RES, SMALL_RES, 4096};
	const size_t	size[3] = {
		convert_to_pagesize(num[0] * res[0] + HEADER_SIZE),
		convert_to_pagesize(num[1] * res[1] + HEADER_SIZE),
		0};

	if (info == SIZE)
		return (size[type]);
	else if (info == NUM)
		return (num[type]);
	else if (info == RES)
		return (res[type]);
	else
		return (0);
}
