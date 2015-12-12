/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 11:20:35 by scollon           #+#    #+#             */
/*   Updated: 2015/12/11 14:17:26 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		ret;
	char	*buf;
	char	**map;
	size_t	size;
	t_tris	*tetri;

	if (argc != 2)
		ft_error(0);
	buf = ft_read(argv[1], &ret);
	ft_isvalid(buf);
	tetri = ft_assign(buf);
	free(buf);
	map = ft_allocmap();
	size = ft_optiminsquare(ret);
	ft_resolve(map, tetri, size, (ret + 1) / 21);
	free(map);
	return (0);
}
