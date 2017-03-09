/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:01:18 by wwatkins          #+#    #+#             */
/*   Updated: 2017/03/07 18:51:37 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	print_nchar(char c, int n)
{
	int i;

	i = -1;
	while (++i < n)
		write(1, &c, 1);
}

void	print_nm(char *name, char type, uint64_t n_value, uint8_t sys)
{
	if (n_value == N_UNDF && type == 'U')
	{
		print_nchar(' ', sys);
		ft_printf(" %c %s\n", type, name);
	}
	else
	{
		print_nchar('0', sys - nbr_len_base(n_value, 16));
		ft_printf("%llx %c %s\n", n_value, type, name);
	}
}

void	output_nm(void *file, t_info *info)
{
	char	type;
	char	*name;
	t_list	*current;
	uint8_t	sys;

	current = info->list;
	sys = (info->sys == X86 ? 8 : 16);
	while (current)
	{
		type = get_symbol_type(current, info);
		name = ((void*)file + ((t_symbol*)current->data)->fileoff);
		print_nm(name, type, ((t_symbol*)current->data)->n_value, sys);
		current = current->next;
	}
}

void	print_otool(void *file, t_list *current, uint8_t sys)
{
	uint32_t	i;
	uint32_t	j;
	uint32_t	size;
	uint64_t	hex;
	t_section	*sect;

	j = 0;
	sect = (t_section*)current->data;
	ft_printf("(%s,%s) section\n", sect->segname, sect->sectname);
	while (j < sect->size)
	{
		print_nchar('0', sys - nbr_len_base((sect->addr + j), 16));
		ft_printf("%llx ", (sect->addr + j));
		size = (sect->size - j < 16 ? sect->size - j : 16);
		i = -1;
		while (++i < size)
		{
			hex = *((char*)file + sect->offset + i + j) & 0xff;
			hex == 0 ? print_nchar('0', 1) : 0;
			ft_printf("%02llx ", hex);
		}
		ft_printf("\n");
		j += 16;
	}
}

void	output_otool(void *file, t_info *info)
{
	t_list		*current;
	uint8_t		sys;

	sys = (info->sys == X86 ? 8 : 16);
	current = info->slist;
	while (current)
	{
		if (ft_strcmp(((t_section*)current->data)->segname, SEG_TEXT) != 0 ||
			ft_strcmp(((t_section*)current->data)->sectname, SECT_TEXT) != 0)
			break ;
		print_otool(file, current, sys);
		current = current->next;
	}
}
