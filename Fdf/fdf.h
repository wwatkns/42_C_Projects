/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:28:05 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/21 21:19:01 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

# include <stdio.h> // TEMPORARY

# define ABS(x) (x < 0 ? -x : x)
# define TAB_SIZE 2048 // UGLY AS FUCK

typedef struct	s_env
{
	void	*mlx;
	void	*win;
}				t_env;

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_line
{
	t_point p0;
	t_point p1;
	int		dx;
	int		dy;
}				t_line;

typedef struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_color;

int		**ft_read(const char *argv, int *tabwidth);
void	ft_tabassign(int **tab, const char *line, int wc, int y);
void	ft_maperror(const char *line);
void	ft_error(int err);

void	ft_core(int **tab, int tabwidth);
void	ft_assigncoor(t_env e, t_point **pts, int **tab, int tabwidth);
void	ft_drawline(t_env e, t_line line, int color);

#endif
