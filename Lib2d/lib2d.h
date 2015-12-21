/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 10:01:59 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/21 14:57:03 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB2D_H
# define LIB2D_H

# include <mlx.h>
# include <unistd.h>

# define ABS(x) (x < 0 ? -x : x)

typedef struct	s_env
{
	void *mlx;
	void *win;
}				t_env;

typedef struct  s_point
{
	int x;
	int y;
}               t_point;

typedef struct  s_line
{
	t_point p0;
	t_point p1;
	int     dx;
	int     dy;
}               t_line;

typedef struct  s_rect
{
	t_point p0;
	t_point p1;
}               t_rect;

typedef struct	s_circle
{
	t_point	p;
	int		r;
}				t_circle;

typedef struct  s_color
{
	unsigned char   r;
	unsigned char   g;
	unsigned char   b;
}               t_color;

/*
** Drawing functions. (draw.c)
*/

void        ft_drawline(t_env e, t_line line, int color);
void		ft_drawrect(t_env e, t_rect rect, int color);
void		ft_drawfillrect(t_env e, t_rect rect, int color);
void        ft_drawcircle(t_env e, t_circle circle, int color);
void		ft_drawfillcircle(t_env e, t_circle circle, int color);

/*
** Initialize struct components functions. (assign.c)
*/

t_point		ft_point(int x, int y);
t_line		ft_line(int x, int y, int x1, int y1);
t_rect		ft_rect(int x, int y, int x1, int y1);
t_circle	ft_circle(int x, int y, int r);

/*
** Color manipulation functions. (color.c)
*/

int			ft_rgb2hex(t_color color);
t_color     ft_hex2rgb(int c);
t_color		ft_rgb(unsigned char r, unsigned char g, unsigned char b);
int			ft_rgbcolor(unsigned char r, unsigned char g, unsigned char b);

#endif
