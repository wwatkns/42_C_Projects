/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:28:05 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/22 16:28:27 by wwatkins         ###   ########.fr       */
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
# define TAB_SIZE 4096 // UGLY AS FUCK

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		grid_w;
	int		grid_h;
	t_point	**pts;
}				t_env;

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

int		**ft_read(t_env *env, const char *argv);
void	ft_tabassign(t_env env, int **tab, const char *line);
void	ft_maperror(const char *line);
void	ft_error(int err);

void	ft_core(t_env *env, int **tab);
void	ft_assigncoor(t_env *env, int **tab);
void	ft_drawline(t_env env, t_line line, int color);
t_line	ft_line(int x, int y, int x1, int y1);

#endif
