/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 10:12:17 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/14 17:46:58 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int const fd, char **line)
{
	int			ret;
	char		*buf;
	static char	*s[255];

	buf = ft_strnew(BUFF_SIZE);
	s[fd] = (s[fd] == NULL ? ft_strnew(1) : s[fd]);
	if (!line || fd < 0 || s[fd] == NULL || buf == NULL)
		return (-1);
	while (!ft_strchr(s[fd], '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		s[fd] = ft_strjoin(s[fd], buf);
	}
	free(buf);
	if (ft_strchr(s[fd], '\n'))
	{
		*line = ft_strsub(s[fd], 0, ft_strchr(s[fd], '\n') - s[fd]);
		s[fd] = ft_strsub(s[fd], ft_strchr(s[fd], '\n') - s[fd] + 1,
				ft_strlen(s[fd]));
	}
	else
		*line = ft_strdup(s[fd]);
	if (ret == -1)
		return (-1);
	return (ret != 0 ? 1 : 0);
}
