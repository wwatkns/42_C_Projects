/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 11:05:06 by wwatkins          #+#    #+#             */
/*   Updated: 2017/03/07 17:55:59 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

int		main(int argc, char **argv)
{
	int			i;
	t_info		info;
	void		*file;
	struct stat	sb;

	if (argc < 2)
		error(ERR_ARGC, "error");
	i = 0;
	info.prog = OTOOL;
	while (++i < argc)
	{
		info.path = argv[i];
		if ((file = mmap_file(argv[i], &sb)) == NULL)
			return (0);
		if (!is_ar(file))
			ft_printf("%s:\n", info.path);
		else
			ft_printf("Archive : %s\n", info.path);
		core(file, &info);
		munmap_file(file, sb.st_size);
		list_delete(&info.list);
		list_delete(&info.slist);
	}
	return (0);
}
