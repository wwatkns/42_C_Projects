/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:28:05 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/04 16:48:37 by wwatkins         ###   ########.fr       */
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

# define BUFFSIZE 32
# define ABS(x) (x < 0 ? -x : x)

typedef struct	s_point
{
	int x;
	int y;
	int h;
}				t_point;

typedef struct	s_key
{
	int	w;
	int	s;
	int a;
	int d;
	int	i;
	int	k;
	int p;
}				t_key;

typedef struct	s_cam
{
	t_point	move;
	t_point	rota;
	int		x;
	int		y;
	int		speed;
	float	alt;
	float	zoom;
}				t_cam;

typedef struct	s_palette
{
	int		c1;
	int		c2;
	int		c3;
	int		c4;
	int		c5;
	int		i;
	float	step;
}				t_palette;

typedef struct	s_img
{
	void	*adr;
	char	*img;
	int		endian;
	int		bpp;
	int		sl;
}				t_img;

typedef struct	s_env
{
	t_point		**pts;
	t_key		key;
	t_cam		cam;
	t_img		img;
	t_palette	palette;
	void		*mlx;
	void		*win;
	int			gw;
	int			gh;
	int			scw;
	int			sch;
	int			minh;
	int			maxh;
	float		ir;
}				t_env;

/*
**	read.c functions
*/

int				**ft_read(t_env *e, const char *argv);
void			ft_tabassign(t_env *e, int **tab, const char *line, int j);
void			ft_getgridsize(t_env *e, const char *argv);
void			ft_maperror(const char *line);
void			ft_error(int err);

/*
**	core.c functions
*/

void			ft_core(t_env *e, int **tab);
void			ft_initenv(t_env *e);
void			ft_initimg(t_env *e);
void			ft_assigncoor(t_env *e, int **tab);
void			ft_displaylines(t_env *e);

/*
**	draw.c functions
*/

void			ft_drawline(t_env e, t_point p, t_point p1);
void			ft_imgpixelput(t_env *e, int x, int y, int color);
int				ft_getcolor(t_env e, t_point p, t_point p1);
void			ft_setpalette(t_env *e, int palette);

/*
 **	hook.c functions
 */

int				ft_keyhook_pressed(int keycode, t_env *e);
int				ft_keyhook_release(int keycode, t_env *e);
int				ft_loophook(t_env *e);
int				ft_exposehook(t_env *e);
int				ft_debugmessage(t_env *e);

#endif
