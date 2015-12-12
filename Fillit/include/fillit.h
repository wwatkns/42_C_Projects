/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:26:00 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/11 16:22:59 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

# define INBUFMAX 546
# define INIT(a, b, c, d, x) (a = b =  c = d = x)

typedef	struct	s_axes
{
	int			x;
	int			y;
}				t_axes;

typedef struct	s_tris
{
	t_axes		p[4];
	char		name;
}				t_tris;

typedef struct	s_var
{
	t_tris	*tetri;
	int		nb;
	int		size;
}				t_var;

/*
** Program functions
*/

/*
**				Functions used to read files and check errors
*/
char			*ft_read(const char *av, int *ret);
void			ft_error(int err);
void			ft_isvalid(const char *s);
int				ft_istetrivalid(const char *s, int i);

/*
**				Functions usefull to handle the map
*/
char			**ft_allocmap(void);
void			ft_setmap(char **map, size_t size);
void			ft_printmap(char **map, size_t size);
void			ft_mapclr(char **map, size_t size);
size_t			ft_optiminsquare(size_t ret);

/*
**				Functions used to save terominoes
*/
t_tris			*ft_assign(char *buf);
void			ft_assigncoor(t_tris *assign, char *buf, int *i, int n);
void			ft_relcoor(t_tris *assign);

/*
**				Functions used to place or remove tetrominoes
*/
int				ft_placet(char **map, t_tris tetri, size_t size);
int				ft_isplacable(char **map, t_tris tmp);
int				ft_movet(t_tris *tmp, size_t size);
void			ft_tetricpy(t_tris *dst, t_tris src);

/*
**				Resolve functions
*/
void			ft_resolve(char **map, t_tris *tetri, size_t size, int nb);
int				ft_solswap(char **map, t_var t, int *sol, int i);
int				ft_checksol(char **map, t_tris *tetri, int nb, int size);
void			ft_initsol(int *sol, int nb);
void			ft_swapindex(int *a, int *b);

#endif
