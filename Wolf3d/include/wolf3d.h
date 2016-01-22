/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 10:57:02 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/22 10:52:37 by wwatkins         ###   ########.fr       */
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
# define DEG2RAD PI / 180
# define RAD2DEG 180 / PI
# define FOV 60

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
	float	fov;
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
	t_vec2	pos;
	int		**map;
	int		size;
	int		w;
	int		h;
}				t_map;

typedef	struct	s_ray
{
	t_vec2	pos;
	t_vec2	dir;
	t_vec2	len;
	t_vec2	a;
	t_vec2i	map;
	t_vec2i	step;
	int		side;
	int		hit;
	float	dist;
}				t_ray;

typedef struct	s_env
{
	t_ray	ray;
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

void			args_get(t_env *e, int argc, char **argv);
void			args_disp(void);
void			error(int err);

/*
**	core.c functions
*/

void			core(t_env *e);
void			env_init(t_env *e);

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

void			draw_line(t_env *e, t_vec2i p, t_vec2i p1);
void			draw_vertical_line(t_env *e, t_vec2 p, int y, int *rgb);
void			img_pixel_put(t_env *e, int x, int y, int *rgb);
void			img_init(t_env *e);
int				*set_rgb(int r, int g, int b);

/*
**	hook.c functions
*/

int				loop_hook(t_env *e);
int				expose_hook(t_env *e);
int				key_pressed(int keycode, t_env *e);
int				key_released(int keycode, t_env *e);

/*
**	map.c functions
*/

void			map_init(t_env *e);
void			map_parse(t_env *e);
void			map_assign(t_env *e, const char *line, int j);

/*
**	raycast.c functions
*/

void			raycast(t_env *e);
void			raycast_init(t_env *e, int x);
void			raycast_calc(t_env *e);
void			raycast_algo(t_env *e);
void			raycast_draw(t_env *e, int x);

#endif
