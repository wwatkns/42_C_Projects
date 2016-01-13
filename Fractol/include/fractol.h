/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 09:25:57 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/13 14:46:00 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <libft.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

# define ABS(x) (x < 0 ? -x : x)

typedef struct	s_mouse
{
	int x;
	int y;
	int	zp;
	int	zm;
}				t_mouse;

typedef struct	s_img
{
	void	*adr;
	char	*img;
	int		endian;
	int		bpp;
	int		opp;
	int		sl;
}				t_img;

typedef struct	s_arg
{
	char	*fract;
	int		w;
	int		h;
}				t_arg;

typedef struct	s_key
{
	int		p;
	int		o;
	int		pu;
	int		pd;
	int		kp;
	int		km;
}				t_key;

typedef struct	s_fract
{
	double	c_re;
	double	c_im;
	double	x;
	double	y;
	double	x2;
	double	y2;
	double	zoom;
	double	offx;
	double	offy;
	double	zwin_w;
	double	zwin_h;
	int		color;
	int		n;
	int		max;
}				t_fract;

typedef struct	s_env
{
	t_key	key;
	t_mouse	mouse;
	t_img	img;
	t_arg	arg;
	t_fract	f;
	void	*mlx;
	void	*win;
	int		win_w;
	int		win_h;
	int		hwin_w;
	int		hwin_h;
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
void			ft_displayfract(t_env *e);
void			ft_initenv(t_env *e);

/*
**	hook.c functions
*/

int				ft_expose_hook(t_env *e);
int				ft_loop_hook(t_env *e);
int				ft_key_pressed(int keycode, t_env *e);
int				ft_key_released(int keycode, t_env *e);
void			ft_debugtext(t_env *e);

/*
**	mousehook.c functions
*/

int				ft_mouse_pos(int x, int y, t_env *e);
int				ft_mouse_hook(int button, int x, int y, t_env *e);

/*
**	draw.c functions
*/

void			ft_imgpixelput(t_env *e, int x, int y, int *rgb);
void			ft_initimg(t_env *e);
int				*ft_getcolor(t_env *e, int i);
int				*ft_setrgb(int r, int g, int b);

/*
**	fractale.c
*/

void			ft_julia(t_env *e, int x, int y);
void			ft_mandelbrot(t_env *e, int x, int y);
void			ft_burningship(t_env *e, int x, int y);
void			ft_tricorn(t_env *e, int x, int y);
void			ft_initfract(t_env *e);

#endif
