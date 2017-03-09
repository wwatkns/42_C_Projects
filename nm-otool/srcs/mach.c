/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mach.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:25:14 by wwatkins          #+#    #+#             */
/*   Updated: 2017/03/07 17:01:39 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	decode_command(void *file, t_info *info)
{
	uint32_t				i;
	int						current_offset;
	struct load_command		*cmd;

	i = -1;
	current_offset = info->header_offset;
	while (++i < info->ncmds)
	{
		cmd = (void*)file + current_offset;
		if (cmd->cmd == LC_SEGMENT)
			decode_segment_x86(file, current_offset, info);
		if (cmd->cmd == LC_SEGMENT_64)
			decode_segment_x64(file, current_offset, info);
		else if (cmd->cmd == LC_SYMTAB && info->sys == X86 && info->prog == NM)
			decode_symbol_table_x86(file, current_offset, info);
		else if (cmd->cmd == LC_SYMTAB && info->sys == X64 && info->prog == NM)
			decode_symbol_table_x64(file, current_offset, info);
		current_offset += cmd->cmdsize;
	}
}
