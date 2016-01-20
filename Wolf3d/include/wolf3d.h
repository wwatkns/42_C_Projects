/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 10:57:02 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/20 11:25:00 by wwatkins         ###   ########.fr       */
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

# include <stdio.h> // TEMPORARY

# define ABS(x) (x < 0 ? -x : x)
# define PI 3.1415926
# define RAD2DEG 180 / PI

typedef struct	s_arg
{
	char	*map;
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

typedef struct	s_vec2i
{
	int	x;
	int	y;
}				t_vec2i;

typedef struct	s_vec2
{
	float	x;
	float	y;
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

typedef struct	s_map
{
	int	**map;
	int	size;
	int	w;
	int	h;
}				t_map;

typedef struct	s_env
{
	t_map	map;
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
void			init_env(t_env *e);

/*
**	vector.c functions
*/

float			vec2_magnitude(t_vec2 vec2);
void			vec2_normalize(t_vec2 *vec2);
t_vec2			vec2_scale(t_vec2 vec2, float scale);
t_vec2			vec2(float x, float y);
t_vec2i			vec2i(t_vec2 vec2);

/*
**	vector_op.c functions
*/

void			vec2_rotate(t_vec2 *vec2, float theta);
t_vec2			vec2_add(t_vec2 vec2_a, t_vec2 vec2_b);
t_vec2			vec2_sub(t_vec2 vec2_a, t_vec2 vec2_b);
t_vec2			vec2_mul(t_vec2 vec2_a, t_vec2 vec2_b);

/*
**	draw.c functions
*/

void			ft_drawline(t_env *e, t_vec2i p, t_vec2i p1);
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

/*
**	map.c functions
*/

void			init_map(t_env *e);
void			parse_map(t_env *e);
void			map_assign(t_env *e, const char *line, int j);

#endif
