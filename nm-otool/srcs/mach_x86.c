/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mach_x86.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 10:34:52 by wwatkins          #+#    #+#             */
/*   Updated: 2017/03/07 19:04:54 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	decode_mach_x86(void *file, t_info *info)
{
	info->header_offset = sizeof(struct mach_header);
	info->ncmds = ((struct mach_header*)file)->ncmds;
	info->sys = X86;
	decode_command(file, info);
}

void	decode_symbol_table_x86(void *file, int offset, t_info *info)
{
	uint32_t				i;
	int						off;
	struct symtab_command	*sym;
	struct nlist			*lst;
	t_symbol				*data;

	i = -1;
	sym = (void*)file + offset;
	while (++i < sym->nsyms)
	{
		off = sym->symoff + i * sizeof(struct nlist);
		lst = (void*)file + off;
		if (!(lst->n_type & N_STAB))
		{
			off = (uint32_t)(sym->stroff + lst->n_un.n_strx);
			data = new_symbol(lst->n_sect, lst->n_type, lst->n_value, off);
			list_push_tail(&info->list, data, sizeof(t_symbol));
			free(data);
		}
	}
}

void	decode_segment_x86(void *file, int offset, t_info *info)
{
	uint32_t				i;
	int						off;
	struct segment_command	*segm;
	struct section			*sec;
	t_section				*data;

	i = -1;
	segm = (void*)file + offset;
	while (++i < segm->nsects)
	{
		off = offset + sizeof(struct segment_command);
		off += sizeof(struct section) * i;
		sec = (void*)file + off;
		data = new_section(sec->segname, sec->sectname, sec->offset, sec->size);
		data->addr = sec->addr;
		list_push_tail(&info->slist, data, sizeof(t_section));
		free(data);
	}
}
