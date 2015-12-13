/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 10:12:17 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/13 10:23:03 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // TEMPORARY

int		get_next_line(int const fd, char **line)
{
	int			i;
	int			ret;
	char		*buf;
	static char	*tmp;

	buf = ft_strnew(BUFF_SIZE);
	tmp = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (i < ret)
		{
			tmp = ft_strjoin(tmp, buf);
			i++;
		}
		buf[BUFF_SIZE] = '\0';
	//	printf("%s", buf);
	}
	*line = ft_strjoin(tmp, buf);
	return (0);
}

int		main(void)
{
	int		fd;
	char	*line;

	if ((fd = open("text.txt", O_RDONLY)) == -1)
		printf("OPEN ERROR.\n");
	line = (char*)malloc(sizeof(char) * 1000);
	get_next_line(fd, &line);
	printf("%s\n", line);
	return (0);
}
