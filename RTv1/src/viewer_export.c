/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 14:52:44 by wwatkins          #+#    #+#             */
/*   Updated: 2016/03/10 17:08:09 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

#define FILE_RIGHTS S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH

static char	*set_file_name(char *name)
{
	char		*file_name;
	char		*tmp;
	time_t		epoch;

	time(&epoch);
	name = ft_strrchr(name, '/');
	name = ft_strchr(name, '.');
	tmp = ft_strjoin(name, "_%d_%m_%Y_%X");
	file_name = malloc(sizeof(char) * 100);
	strftime(file_name, 50, tmp, localtime(&epoch));
	ft_strdel(&tmp);
	file_name = ft_strjoin("./resource/images/", file_name);
	file_name = ft_strjoin(file_name, ".mlx");
	printf("file: %s\n", file_name);
	return (file_name);
}

void		viewer_export(t_env *e)
{
	char		*file_name;
	int			len;
	int			fd;

	file_name = set_file_name(e->arg.file_scene);
	fd = open(file_name, O_WRONLY | O_CREAT, FILE_RIGHTS);
	ft_strdel(&file_name);
	len = e->img.sl * e->win.h;
	ft_putnbr_fd(e->win.w, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(e->win.h, fd);
	write(fd, "\n", 1);
	write(fd, e->img.img, len);
	close(fd);
}
