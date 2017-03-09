/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 11:03:15 by wwatkins          #+#    #+#             */
/*   Updated: 2017/03/07 17:49:37 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

int		main(int argc, char **argv)
{
	int			i;
	t_info		info;
	void		*file;
	struct stat	sb;

	i = (argc < 2 ? -1 : 0);
	info.prog = NM;
	while (++i < argc)
	{
		info.path = argc < 2 ? "a.out" : argv[i];
		if ((file = mmap_file(info.path, &sb)) == NULL)
			return (0);
		if (argc > 2 && !is_ar(file) && !is_fat(*(int*)file))
			ft_printf("\n%s:\n", info.path);
		core(file, &info);
		munmap_file(file, sb.st_size);
		list_delete(&info.list);
		list_delete(&info.slist);
	}
	return (0);
}
