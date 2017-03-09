/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:46:55 by wwatkins          #+#    #+#             */
/*   Updated: 2017/03/07 19:05:14 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

uint32_t	swap_uint32(uint32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return ((val << 16) | (val >> 16));
}

t_symbol	*new_symbol(uint8_t sec, uint8_t type, uint64_t val, uint32_t off)
{
	t_symbol	*new;

	new = malloc(sizeof(t_symbol));
	new->n_type = type;
	new->n_sect = sec;
	new->n_value = val;
	new->fileoff = off;
	return (new);
}

t_section	*new_section(char *seg, char *sec, uint32_t offset, uint32_t size)
{
	t_section	*new;

	new = malloc(sizeof(t_section));
	ft_strcpy(new->segname, seg);
	ft_strcpy(new->sectname, sec);
	new->offset = offset;
	new->size = size;
	return (new);
}

void		bubble_sort(void *file, t_list *head)
{
	int			swapped;
	char		*name;
	t_list		*current;
	t_list		*tmp;

	tmp = NULL;
	swapped = 1;
	if (head == NULL)
		return ;
	while (swapped)
	{
		swapped = 0;
		current = head;
		while (current->next != tmp)
		{
			name = ((void*)file + ((t_symbol*)current->data)->fileoff);
			if (ft_strcmp(name, ((void*)file + \
				((t_symbol*)current->next->data)->fileoff)) > 0)
				swapped = swap(current, current->next);
			current = current->next;
		}
		tmp = current;
	}
}

int			swap(t_list *a, t_list *b)
{
	void	*tmp;

	tmp = a->data;
	a->data = b->data;
	b->data = tmp;
	return (1);
}
