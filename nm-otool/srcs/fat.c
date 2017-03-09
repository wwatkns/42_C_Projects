/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:51:51 by wwatkins          #+#    #+#             */
/*   Updated: 2017/03/07 18:46:34 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	decode_arch(void *file, t_info *info)
{
	struct fat_header	*header;
	struct fat_arch		*arch;
	uint32_t			i;
	uint32_t			offset;
	uint32_t			rnfat_arch;

	i = -1;
	header = (struct fat_header*)file;
	arch = (void*)file + sizeof(struct fat_header);
	rnfat_arch = swap_uint32(header->nfat_arch);
	while (++i < rnfat_arch)
	{
		if (swap_uint32(arch->cputype) == CPU_TYPE_X86_64)
			offset = arch->offset;
		arch++;
	}
	core(file + swap_uint32(offset), info);
}

void	decode_fat(void *file, t_info *info)
{
	info->header_offset = sizeof(struct fat_header);
	info->sys = X64;
	decode_arch(file, info);
}
