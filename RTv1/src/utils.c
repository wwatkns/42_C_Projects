/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:56:39 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/11 11:30:55 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		str_digit(char *str)
{
	while (*str)
		if (ft_isdigit(*str++))
			return (1);
	return (0);
}

int		parse_type(char *line)
{
	int	type;

	ft_strstr(line, "cone") ? type = CONE : 0;
	ft_strstr(line, "plane") ? type = PLANE : 0;
	ft_strstr(line, "sphere") ? type = SPHERE : 0;
	ft_strstr(line, "cylinder") ? type = CYLINDER : 0;
	return (type);
}

t_vec3	parse_vector(char *line)
{
	int		i;
	int		n;
	char	**split;
	t_vec3	vec3;

	i = 0;
	n = 0;
	vec3 = (t_vec3) { 0.0, 0.0, 0.0 };
	split = ft_strsplit(line, ' ');
	while (split[i] != NULL && n != 3)
	{
		str_digit(split[i]) == 1 ? n++ : 0;
		n == 1 ? vec3.x = ft_atof(split[i]) : 0;
		n == 2 ? vec3.y = ft_atof(split[i]) : 0;
		n == 3 ? vec3.z = ft_atof(split[i]) : 0;
		ft_strdel(&split[i]);
		i++;
	}
	ft_strdel(split);
	vec3_clamp(&vec3, MIN_POS, MAX_POS);
	return (vec3);
}
