/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 14:14:22 by wwatkins          #+#    #+#             */
/*   Updated: 2017/03/07 18:48:25 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	list_push_head(t_list **head, void *data, uint32_t bytes)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->data = malloc(bytes);
	ft_memcpy(new->data, data, bytes);
	new->next = *head;
	*head = new;
}

void	list_push_tail(t_list **head, void *data, uint32_t bytes)
{
	t_list	*current;

	current = *head;
	if (!current)
	{
		list_push_head(head, data, bytes);
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = malloc(sizeof(t_list));
	current->next->data = malloc(bytes);
	ft_memcpy(current->next->data, data, bytes);
	current->next->next = NULL;
}

void	list_delete(t_list **head)
{
	t_list	*current;
	t_list	*next;

	current = *head;
	while (current)
	{
		next = current->next;
		free(next);
		current = next;
	}
	*head = NULL;
}
