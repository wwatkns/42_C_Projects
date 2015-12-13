/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 10:12:17 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/13 11:51:10 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // TEMPORARY

static int	ft_checkbuf(char *buf) // Ok
{
	int i;

	i = 0;
	while (i < BUFF_SIZE)
	{
		if (buf[i] == '\n' || buf[i] == EOF)
			return (i);
		i++;
	}
	return (-1);
}

int			get_next_line(int const fd, char **line)
{
	int			i;
	int			n;
	int			ret;
	char		*buf;
	static char	*tmp = NULL;

	if ((buf = ft_strnew(BUFF_SIZE)) == NULL)
		return (-1);
	if ((tmp = ft_strnew(BUFF_SIZE)) == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (ret == -1)
			return (-1);
		buf[BUFF_SIZE + 1] = '\0';
		n = ft_checkbuf(buf);
		tmp = ft_strjoin(tmp, (n != -1 ? ft_strsub(buf, 0, n) : buf));
		if (n != -1)
			break ;
	}
	ft_strcpy(*line, tmp);
	return (0);
}

int			main(void)
{
	int		fd;
	char	*line;

	if ((fd = open("text.txt", O_RDONLY)) == -1)
		printf("OPEN ERROR.\n");
	line = ft_strnew(1000);
	get_next_line(fd, &line);
	printf("%s", line);
	return (0);
}
