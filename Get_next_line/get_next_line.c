/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 10:12:17 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/14 12:54:54 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int const fd, char **line)
{
	int			ret;
	char		*buf;
	static char	*tmp;

	tmp = (tmp == NULL ? ft_strnew(1) : tmp);
	if ((buf = ft_strnew(BUFF_SIZE)) == NULL || tmp == NULL)
		return (-1);
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
