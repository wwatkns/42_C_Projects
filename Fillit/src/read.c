/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:39:18 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/11 15:47:46 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read(const char *av, int *ret)
{
	int		fd;
	char	*buf;

	ft_error((int)(buf = (char*)malloc(sizeof(char) * INBUFMAX)));
	ft_error((fd = open(av, O_RDONLY)));
	ft_error((*ret = read(fd, buf, INBUFMAX)));
	buf[*ret] = '\0';
	ft_isvalid(buf);
	return (buf);
}

void	ft_isvalid(const char *s)
{
	int i;
	int n;
	int p;
	int t;
	int	k;

	p = 0;
	INIT(i, n, t, k, 0);
	while (s[i] != '\0')
	{
		ft_error(!(s[i] != '.' && s[i] != '#' && s[i] != '\n'));
		ft_error((i - t == 20 ? ft_istetrivalid(s, i - 20) : 1));
		n = (s[i] == '\n' ? n + 1 : n);
		p = (s[i] == '.' ? p + 1 : p);
		t = (i - t == 20 ? i + 1 : t);
		k = (s[i] == '#' ? k + 1 : k);
		i++;
		ft_error(!(s[i] == '\0' && i >= 546));
		ft_error(!(s[i] == '\0' && i < 20));
		ft_error(!(s[i] == '\0' && s[i - 2] == '\n'));
	}
	ft_error(!(p != ((i + 1) / 21) * 12));
	ft_error(!(n != ((i + 1) / 21) * 4 + ((i + 1) / 21) - 1));
	ft_error(!(k != ((i + 1) / 21) * 4));
	ft_error((ft_istetrivalid(s, i - 20)));
}

int		ft_istetrivalid(const char *s, int i)
{
	int j;
	int t;

	j = i;
	t = 0;
	while (j - i < 20)
	{
		t = (s[j] == '#' && s[j - 5] == '#' && j >= 5 ? t + 1 : t);
		t = (s[j] == '#' && s[j + 5] == '#' && j - 5 < INBUFMAX ? t + 1 : t);
		t = (s[j] == '#' && s[j - 1] == '#' && j >= 1 ? t + 1 : t);
		t = (s[j] == '#' && s[j + 1] == '#' && j - 1 < INBUFMAX ? t + 1 : t);
		j++;
	}
	return (!(t < 6));
}

void	ft_error(int err)
{
	if (err == 0 || err == -1)
	{
		ft_putstr_fd("error\n", 2);
		exit(0);
	}
}
