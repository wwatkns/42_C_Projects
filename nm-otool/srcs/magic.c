/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 15:29:25 by wwatkins          #+#    #+#             */
/*   Updated: 2017/03/01 17:52:00 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

int	is_magic(uint32_t magic)
{
	return (magic == MH_MAGIC || magic == MH_CIGAM);
}

int	is_magic_64(uint32_t magic)
{
	return (magic == MH_MAGIC_64 || magic == MH_CIGAM_64);
}

int	is_fat(uint32_t magic)
{
	return (magic == FAT_MAGIC || magic == FAT_CIGAM);
}

int	is_ar(void *file)
{
	return (ft_strncmp(file, ARMAG, SARMAG) == 0);
}

int	is_swap(uint32_t magic)
{
	return (magic == MH_CIGAM || magic == MH_CIGAM_64 || magic == FAT_CIGAM);
}
