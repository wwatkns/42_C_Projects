/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 10:54:12 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/09 14:23:40 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <libft.h>
# include <libvec.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>

# include <stdio.h> // temporary

# define ABS(x) (x < 0 ? -x : x)

enum { SPHERE, CONE, PLANE, CYLINDER };

typedef struct	s_arg
{
	char	*file_scene;
	int		w;
	int		h;
}				t_arg;

typedef struct	s_img
{
	void	*adr;
	char	*img;
	int		endian;
	int		bpp;
	int		opp;
	int		sl;
}				t_img;

typedef struct	s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_rgb;

typedef struct	s_obj
{
	t_vec3			pos;
	t_vec3			dir;
	t_rgb			rgb;
	short			type;
	double			scale;
	int				color;
	int				index;
	struct s_obj	*next;
}				t_obj;

typedef struct	s_cam
{
	t_vec3	pos;
	t_vec3	dir;
	t_vec3	origin;
	double	dist;
	double	w;
	double	h;
	double	xi;
	double	yi;
	int		fov;
}				t_cam;

typedef struct	s_lgt
{
	t_vec3			pos;
	int				color;
	struct s_lgt	*next;
}				t_lgt;

typedef struct	s_ray
{
	t_vec3		pos;
	t_vec3		dir;
	t_vec3		hit;
	int			x;
	int			y;
	int			dist;
}				t_ray;

typedef struct	s_win
{
	void	*adr;
	int		w;
	int		h;
	int		dw;
	int		dh;
}				t_win;

typedef struct	s_env
{
	t_win	win;
	t_arg	arg;
	t_img	img;
	t_cam	cam;
	t_lgt	lgt;
	t_obj	*obj;
	t_ray	ray;
	void	*mlx;
}				t_env;

/*
**	main.c functions
*/

void			args_get(t_env *e, int argc, char **argv);
void			args_disp(void);
void			error(int err);

/*
**	parse.c functions
*/

void			parse_scene(t_env *e);
void			parse_camera(t_env *e, int fd);
void			parse_light(t_env *e, int fd);
t_vec3			parse_vector(char *line);
t_obj			*create_object(int fd);

/*
**	utils.c functions
*/

int				str_digit(char *str);

/*
**	core.c	functions
*/

void			core(t_env *e);
void			env_init(t_env *e);
void			list_init(t_obj	*obj);
void			cam_init(t_env *e);

/*
**	hook.c functions
*/

int				loop_hook(t_env *e);
int				expose_hook(t_env *e);
int				key_pressed(int keycode, t_env *e);

/*
**	draw.c functions
*/

void			img_init(t_env *e);
void			img_pixel_put(t_env *e, int x, int y, t_rgb rgb);
t_rgb			hex_to_rgb(int color);
t_rgb			set_rgb(unsigned char r, unsigned char g, unsigned char b);

/*
**	raytracing.c functions
*/

void			raytracing(t_env *e);
void			raytracing_init(t_env *e);
void			raytracing_calc(t_env *e);
void			raytracing_draw(t_env *e);

/*
**	ray_intersect.c functions
*/

t_obj			*ray_intersect(t_env *e, double *tmin, double *t);
double			ray_intersect_cone(t_env *e, t_obj *obj);
double			ray_intersect_plane(t_env *e, t_obj *obj);
double			ray_intersect_sphere(t_env *e, t_obj *obj);
double			ray_intersect_cylinder(t_env *e, t_obj *obj);

#endif
