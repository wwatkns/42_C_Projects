/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:28:30 by wwatkins          #+#    #+#             */
/*   Updated: 2017/03/07 18:50:12 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

char	get_symbol_section(uint8_t n_sect, t_info *info)
{
	int			i;
	t_list		*current;
	t_section	*sect;

	i = 1;
	current = info->slist;
	while (current)
	{
		if (i >= n_sect)
			break ;
		i++;
		current = current->next;
	}
	sect = current->data;
	if (ft_strcmp(sect->sectname, SECT_TEXT) == 0)
		return ('t');
	else if (ft_strcmp(sect->sectname, SECT_DATA) == 0)
		return ('d');
	else if (ft_strcmp(sect->sectname, SECT_BSS) == 0 ||
			ft_strcmp(sect->sectname, "__compact_unwind__LD") == 0)
		return ('b');
	return ('s');
}

char	get_symbol_type(t_list *current, t_info *info)
{
	char		type;
	t_symbol	*sym;

	sym = current->data;
	type = '?';
	if (sym->n_type & N_STAB)
		type = '-';
	else if ((sym->n_type & N_TYPE) == N_UNDF)
		type = 'u';
	else if ((sym->n_type & N_TYPE) == N_ABS)
		type = 'a';
	else if ((sym->n_type & N_TYPE) == N_SECT)
		type = get_symbol_section(sym->n_sect, info);
	else if ((sym->n_type & N_TYPE) == N_PBUD)
		type = 'u';
	else if ((sym->n_type & N_TYPE) == N_INDR)
		type = 'i';
	if ((sym->n_type & N_EXT) && type != '?')
		type = ft_toupper(type);
	return (type);
}
