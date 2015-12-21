/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 19:09:39 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/21 19:15:19 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlxmain(int **tab, int w)
{
	t_env e;

	ft_error((int)(e.mlx = mlx_init()));
	ft_error((int)(e.win = mlx_new_window(e.mlx, 1280, 720, "Fdf")));
	mlx_loop(e.mlx);
}
