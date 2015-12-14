/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 12:42:07 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/14 12:44:36 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int         main(void) // TEMPORARY
{
	int     fd;
	char    *line;

	if ((fd = open("text.txt", O_RDONLY)) == -1)
		printf("OPEN ERROR.\n");
	line = ft_strnew(1000);
	while (get_next_line(fd, &line))
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	return (0);
}
