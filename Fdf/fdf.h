/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:28:05 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/21 19:15:04 by wwatkins         ###   ########.fr       */
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

# define TAB_SIZE 2048 // UGLY AS FUCK

typedef struct	s_env
{
	void	*mlx;
	void	*win;
}				t_env;

int		**ft_read(const char *argv, int *tabwidth);
void	ft_tabassign(int **tab, const char *line, int wc, int y);
void	ft_maperror(const char *line);
void	ft_error(int err);

void	ft_mlxmain(int **tab, int w);

#endif
