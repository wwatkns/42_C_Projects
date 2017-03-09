/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ar.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:17:43 by wwatkins          #+#    #+#             */
/*   Updated: 2017/03/07 19:03:00 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static uint32_t	ar_size(char *name)
{
	char	*c;

	c = ft_strchr(name, '/');
	return (ft_atoi(c + 1));
}

static void		sort_ranlib(t_ran *ran, uint32_t n)
{
	uint32_t	i;
	uint32_t	j;
	t_ran		tmp;

	n = n - 1;
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n - i)
		{
			if (ran[j].ran_off > ran[j + 1].ran_off)
			{
				tmp = ran[j + 1];
				ran[j + 1] = ran[j];
				ran[j] = tmp;
			}
		}
	}
}

static void		print_ranlib(t_ran *ran, uint32_t nbr, t_info *info)
{
	uint32_t	i;
	uint32_t	j;
	uint8_t		clone;

	i = -1;
	while (++i < nbr)
	{
		clone = 0;
		j = -1;
		while (++j < i)
			if (ran[j].ran_off == ran[i].ran_off)
				clone = 1;
		if (!clone)
		{
			if (info->prog == NM)
				ft_printf("\n%s(%s):\n", info->path, ran[i].name);
			else
				ft_printf("%s(%s):\n", info->path, ran[i].name);
			core(ran[i].obj, info);
		}
	}
}

static t_ran	*decode_ranlib(void *file, struct ar_hdr *ar, uint32_t *nbr)
{
	void			*obj;
	struct ranlib	*ranlib;
	t_ran			*ranarr;
	uint32_t		i;
	uint32_t		r;

	r = 0;
	i = -1;
	ranlib = (void*)ar + sizeof(struct ar_hdr) + ar_size(ar->ar_name) + 4;
	ranarr = (t_ran*)malloc(sizeof(t_ran) * *nbr);
	while (++i < *nbr)
	{
		ar = (void*)file + ranlib[i].ran_off;
		obj = (void*)ar + sizeof(struct ar_hdr) + ar_size(ar->ar_name);
		ranarr[r].ran_off = ranlib[i].ran_off;
		ranarr[r].name = ar->ar_name + sizeof(struct ar_hdr);
		ranarr[r].obj = obj;
		r++;
	}
	*nbr = r;
	return (ranarr);
}

void			decode_ar(void *file, t_info *info)
{
	struct ar_hdr	*ar;
	t_ran			*ranarr;
	uint32_t		n;

	ar = (void*)file + SARMAG;
	n = *((int*)((void*)ar + sizeof(struct ar_hdr) + ar_size(ar->ar_name)));
	n = n / sizeof(struct ranlib);
	ranarr = decode_ranlib(file, ar, &n);
	if (ft_strcmp((ar->ar_name + sizeof(struct ar_hdr)), SYMDEF_SORTED) == 0)
		sort_ranlib(ranarr, n);
	print_ranlib(ranarr, n, info);
}
