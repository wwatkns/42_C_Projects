/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 12:42:07 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/14 17:34:59 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int         main(int argc, char **argv)
{
	int     fd;
	char    *line;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		printf("OPEN ERROR.\n");
	line = ft_strnew(1000);
//	get_next_line(fd, &line);
//	printf("%s", line);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	argc = 0;
	return (0);
}
