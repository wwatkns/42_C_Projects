/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 10:57:02 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/18 12:17:24 by wwatkins         ###   ########.fr       */
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
**	draw.c functions
*/

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
