/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:01:22 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/29 13:08:18 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_scene(t_env *e)
{
	int		fd;
	char	*line;
	t_obj	*current;

	current = e->obj;
	error((fd = open(e->arg.file_scene, O_RDWR)));
	ft_strdel(&e->arg.file_scene);
	while (get_next_line(fd, &line) > 0)
	{
		!ft_strcmp(line, "camera") ? parse_camera(e, fd) : 0;
		!ft_strcmp(line, "light") ? parse_light(e, fd) : 0;
		if (!ft_strcmp(line, "object"))
		{
			current->next = create_object(fd);
			current = current->next;
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	error((close(fd) + 1));
}

void	parse_camera(t_env *e, int fd)
{
	char	*line;

	get_next_line(fd, &line);
	e->cam.pos = parse_vector(line);
	ft_strdel(&line);
	get_next_line(fd, &line);
	e->cam.dir = parse_vector(line);
	ft_strdel(&line);
}

void	parse_light(t_env *e, int fd)
{
	char	*line;

	get_next_line(fd, &line);
	e->lgt.pos = parse_vector(line);
	ft_strdel(&line);
	get_next_line(fd, &line);
	e->lgt.color = ft_atoi_base(line, 16);
	ft_strdel(&line);
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
		n == 1 ? vec3.x = ft_atof(split[i]) : 0;
		n == 2 ? vec3.y = ft_atof(split[i]) : 0;
		n == 3 ? vec3.z = ft_atof(split[i]) : 0;
		ft_strdel(&split[i]);
		i++;
	}
	ft_strdel(split);
	return (vec3);
}

t_obj	*create_object(int fd)
{
	static int	index = 0;
	char		*line;
	t_obj		*obj;

	error((int)(obj = (t_obj*)malloc(sizeof(t_obj))));
	get_next_line(fd, &line);
	ft_strstr(line, "cone") ? obj->type = CONE : 0;
	ft_strstr(line, "plane") ? obj->type = PLANE : 0;
	ft_strstr(line, "sphere") ? obj->type = SPHERE : 0;
	ft_strstr(line, "cylinder") ? obj->type = CYLINDER : 0;
	ft_strdel(&line);
	get_next_line(fd, &line);
	obj->pos = parse_vector(line);
	ft_strdel(&line);
	get_next_line(fd, &line);
	obj->dir = parse_vector(line);
	ft_strdel(&line);
	get_next_line(fd, &line);
	obj->size = parse_vector(line);
	ft_strdel(&line);
	get_next_line(fd, &line);
	(obj->color = ft_atoi_base(line, 16)) ? ft_strdel(&line) : 0;
	obj->index = index++;
	obj->next = NULL;
	return (obj);
}
