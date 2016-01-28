/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:01:22 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/28 17:46:41 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_scene(t_env *e)
{
	int		fd;
	char	*line;

	error((fd = open(e->arg.file_scene, O_RDWR)));
	ft_strdel(&e->arg.file_scene);
	while (get_next_line(fd, &line) > 0)
	{
		if (!ft_strcmp(line, "object"))
			e->obj = create_object(fd); // temporary
		ft_strdel(&line);
	}
	ft_strdel(&line);
	error((close(fd) + 1));
}

t_obj	create_object(int fd)
{
	static int	index = 0;
	char		*line;
	t_obj		obj;

	get_next_line(fd, &line);
	ft_strstr(line, "cone") ? obj.type = CONE : 0;
	ft_strstr(line, "plane") ? obj.type = PLANE : 0;
	ft_strstr(line, "sphere") ? obj.type = SPHERE : 0;
	ft_strstr(line, "cylinder") ? obj.type = CYLINDER : 0;
	ft_strdel(&line);
	get_next_line(fd, &line);
	obj.pos = parse_vector(line);
	ft_strdel(&line);
	get_next_line(fd, &line);
	obj.dir = parse_vector(line);
	ft_strdel(&line);
	get_next_line(fd, &line);
	obj.size = parse_vector(line);
	ft_strdel(&line);
	get_next_line(fd, &line);
	(obj.color = ft_atoi_base(line, 16)) ? ft_strdel(&line) : 0;
	obj.index = index;
	obj.next = NULL;
	index++;
	return (obj);
}

t_vec3	parse_vector(char *line)
{
	int		i;
	int		n;
	char	**split;
	t_vec3	vec3;

	i = 0;
	n = 0;
	split = ft_strsplit(line, ' ');
	while (split[i] != NULL && n != 3)
	{
		str_digit(split[i]) == 1 ? n++ : 0;
		n == 1 ? vec3.x = ft_atoi(split[i]) : 0;
		n == 2 ? vec3.y = ft_atoi(split[i]) : 0;
		n == 3 ? vec3.z = ft_atoi(split[i]) : 0;
		free(split[i]);
		i++;
	}
	free(split);
	return (vec3);
}

int		str_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}
