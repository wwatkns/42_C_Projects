/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 16:26:43 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/28 13:14:59 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H

# include <math.h>

# define ABS(x) (x < 0 ? -x : x)
# define PI 3.1415926
# define DEG2RAD PI / 180
# define RAD2DEG 180 / PI

enum { X, Y, Z };

typedef struct	s_vec3
{
	float	x;
	float	y;
	float	z;
}				t_vec3;

typedef struct	s_vec3i
{
	int		x;
	int		y;
	int		z;
}				t_vec3i;

typedef struct	s_vec2
{
	float	x;
	float	y;
}				t_vec2;

typedef struct	s_vec2i
{
	int		x;
	int		y;
}				t_vec2i;

/*
**	vector2.c functions
*/

t_vec2			vec2(float x, float y);
t_vec2i			vec2i(t_vec2 vec2);
t_vec2			vec2_scale(t_vec2 vec2a, float scale);
float			vec2_magnitude(t_vec2 vec2);
void			vec2_normalize(t_vec2 *vec2);

/*
**	vector2_op.c functions
*/

t_vec2			vec2_add(t_vec2 vec2a, t_vec2 vec2b);
t_vec2			vec2_sub(t_vec2 vec2a, t_vec2 vec2b);
t_vec2			vec2_mul(t_vec2 vec2a, t_vec2 vec2b);
float			vec2_dot(t_vec2 vec2a, t_vec2 vec2b);
void			vec2_rot(t_vec2 *vec2, float theta);

/*
**	vector3.c functions
*/

t_vec3			vec3(float x, float y, float z);
t_vec3i			vec3i(t_vec3 vec3);
t_vec3			vec3_scale(t_vec3 vec3a, float scale);
float			vec3_magnitude(t_vec3 vec3);
void			vec3_normalize(t_vec3 *vec3);

/*
**	vector3_op.c functions
*/

t_vec3			vec3_add(t_vec3 vec3a, t_vec3 vec3b);
t_vec3			vec3_sub(t_vec3 vec3a, t_vec3 vec3b);
t_vec3			vec3_mul(t_vec3 vec3a, t_vec3 vec3b);
float			vec3_dot(t_vec3 vec3a, t_vec3 vec3b);
void			vec3_rot(t_vec3 *vec3, int axis, float theta);

#endif
