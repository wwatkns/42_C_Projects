/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 10:57:02 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/18 15:41:34 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <libft.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define ABS(x) (x < 0 ? -x : x)

typedef struct	s_arg
{
	int		w;
	int		h;
}				t_arg;

typedef struct	s_key
{
	short	w;
	short	s;
	short	a;
	short	d;
	short	q;
	short	e;
}				t_key;

typedef struct	s_vec2
{
	int	x;
	int	y;
}				t_vec2;

typedef struct	s_cam
{
	t_vec2	dir;
	t_vec2	pos;
	t_vec2	pln;
}				t_cam;

typedef struct	s_img
{
	void	*adr;
	char	*img;
	int		endian;
	int		bpp;
	int		opp;
	int		sl;
}				t_img;

typedef struct	s_env
{
	t_cam	cam;
	t_img	img;
	t_key	key;
	t_arg	arg;
	void	*win;
	void	*mlx;
	int		win_w;
	int		win_h;
}				t_env;

/*
**	main.c functions
*/

void			ft_getargs(t_env *e, int argc, char **argv);
void			ft_dispargs(void);
void			ft_error(int err);

/*
**	core.c functions
*/

void			ft_core(t_env *e);
void			ft_initenv(t_env *e);

/*
**	wolf3d.c functions
*/



/*
**	draw.c functions
*/

void			ft_drawline(t_env *e, t_vec2 p, t_vec2 p1);
t_vec2			ft_setvec2(int x, int y);
void			ft_imgpixelput(t_env *e, int x, int y, int *rgb);
void			ft_initimg(t_env *e);
int				*ft_setrgb(int r, int g, int b);

/*
**	hook.c functions
*/

int				ft_loop_hook(t_env *e);
int				ft_expose_hook(t_env *e);
int				ft_key_pressed(int keycode, t_env *e);
int				ft_key_released(int keycode, t_env *e);

#endif
