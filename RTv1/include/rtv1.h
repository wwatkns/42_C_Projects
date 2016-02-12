/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 10:54:12 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/12 14:51:18 by wwatkins         ###   ########.fr       */
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
# define MIN_POS -1000.0
# define MAX_POS 1000.0

enum { SPHERE, CONE, PLANE, CYLINDER };

typedef struct	s_arg
{
	char	*file_scene;
	int		w;
	int		h;
	int		s;
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

typedef struct	s_mat
{
	t_vec3	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}				t_mat;

typedef struct	s_obj
{
	t_vec3			pos;
	t_vec3			dir;
	t_vec3			normal;
	t_mat			mat;
	short			type;
	double			scale;
	struct s_obj	*next;
}				t_obj;

typedef struct	s_cam
{
	t_vec3	pos;
	t_vec3	dir;
	t_vec3	origin;
	double	fov;
	double	dist;
	double	invgamma;
	double	w;
	double	h;
	double	xi;
	double	yi;
	double	supersampling;
	double	supersampling_coeff;
	double	supersampling_inc;
}				t_cam;

typedef struct	s_lgt
{
	t_vec3			pos;
	t_vec3			color;
	double			intensity;
	struct s_lgt	*next;
}				t_lgt;

typedef struct	s_ray
{
	t_vec3		pos;
	t_vec3		dir;
	t_vec3		hit;
	int			x;
	int			y;
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
	t_obj	*obj;
	t_lgt	*light;
	t_ray	ray;
	t_vec3	color;
	t_vec3	color_t;
	t_vec3	color_out;
	double	shadow;
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
void			create_camera(t_env *e, int fd);
t_lgt			*create_light(int fd);
t_obj			*create_object(int fd);
t_mat			create_material(int fd);

/*
**	set.c functions
*/

void			init_camera(t_env *e);
void			init_object(t_obj *obj);
void			init_material(t_mat *mat);
void			init_light(t_lgt *light);

/*
**	utils.c functions
*/

int				str_digit(char *str);
int				parse_type(char *line);
t_vec3			parse_vector(char *line);
void			set_gamma(t_env *e);

/*
**	core.c	functions
*/

void			core(t_env *e);
void			env_init(t_env *e);
void			cam_init(t_env *e);

/*
**	hook.c functions
*/

int				loop_hook(t_env *e);
int				expose_hook(t_env *e);
int				key_pressed(int keycode);

/*
**	draw.c functions
*/

void			img_init(t_env *e);
void			img_pixel_put(t_env *e, int x, int y, t_vec3 color);
void			img_pixel_put_hex(t_env *e, int x, int y, int hex);
t_vec3			hex_to_color(int hex);

/*
**	raytracing.c functions
*/

void			raytracing(t_env *e);
void			raytracing_init(t_env *e, double i, double j);
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

/*
**	light.c functions
*/

void			set_light(t_env *e, t_lgt *light);
void			set_normal(t_env *e, t_obj *obj);
void			set_shadows(t_env *e, t_obj *obj, double *tmin, double *t);
t_vec3			set_diffuse(t_env *e, t_obj *obj, t_lgt *light);
t_vec3			set_specular(t_env *e, t_obj *obj, t_lgt *light);

#endif
