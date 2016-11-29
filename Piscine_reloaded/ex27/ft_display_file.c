/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:04:26 by wwatkins          #+#    #+#             */
/*   Updated: 2016/11/23 17:04:40 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototype.h"

int		ft_return_error(int argc)
{
	if (argc > 2)
	{
		ft_putstr_fd(2, "Too many arguments.\n");
		return (1);
	}
	if (argc < 2)
	{
		ft_putstr_fd(2, "File name missing.\n");
		return (1);
	}
	return (0);
}

int		ft_display_file(char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(2, "Open error.\n");
		return (1);
	}
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		ft_putstr_fd(1, buf);
	}
	if (close(fd) == -1)
	{
		ft_putstr_fd(2, "Close error.\n");
		return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (ft_return_error(argc) == 1)
		return (0);
	if (ft_display_file(argv) == 1)
		return (0);
	return (0);
}
