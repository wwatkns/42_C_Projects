/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:01:22 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/28 15:07:31 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_scene(t_env *e)
{
	int		fd;
	char	*line;

	error((fd = open(e->rg.file_name, O_RDWR)));
	ft_strdel(&e->arg.file_scene);
	while (get_next_line(fd, &line) > 0)
	{
		ft_strdel(&line);
	}
	ft_strdel(&line);
	error((close(fd) + 1));
}
