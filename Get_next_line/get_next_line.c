/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 10:12:17 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/14 11:01:36 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // TEMPORARY

int			get_next_line(int const fd, char **line)
{
	int			ret;
	char		*buf;
	static char	*tmp;

	buf = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	tmp = (tmp == NULL ? ft_strnew(1) : tmp);
	while (!ft_strchr(tmp, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		tmp = ft_strjoin(tmp, buf);
	}
	if (ret > 0)
	{
		*line = ft_strsub(tmp, 0, ft_strchr(tmp, '\n') - tmp + 1);
		line[0][ft_strlen(*line) - 1] = 0;
		tmp = ft_strsub(tmp, ft_strchr(tmp, '\n') - tmp + 1, ft_strlen(tmp));
	}
	free(buf);
	return (ret != 0 ? 1 : 0);
}

int			main(void) // TEMPORARY
{
	int		fd;
	char	*line;

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
