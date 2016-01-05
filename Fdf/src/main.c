/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:27:53 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/05 11:42:07 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_env	e;
	int		**tab;

	ft_error(!(argc != 2));
	tab = ft_parse(&e, argv[1]);
	ft_core(&e, tab);
	free(tab);
	free(&e);
	return (0);
}
