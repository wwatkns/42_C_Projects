/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:01:22 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/10 18:07:15 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_scene(t_env *e)
{
	int		fd;
	char	*line;
	t_obj	*obj;
	t_lgt	*light;

	obj = e->obj;
	light = e->light;
	error((fd = open(e->arg.file_scene, O_RDWR)));
	ft_strdel(&e->arg.file_scene);
	while (get_next_line(fd, &line) > 0)
	{
		!ft_strcmp(line, "camera") ? parse_camera(e, fd) : 0;
		if (!ft_strcmp(line, "light"))
		{
			light->next = create_light(fd);
			light = light->next;
		}
		if (!ft_strcmp(line, "object"))
		{
			obj->next = create_object(fd);
			obj = obj->next;
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
	get_next_line(fd, &line);
	e->cam.fov = ft_atof(ft_strstr(line, "=") + 1);
	ft_strdel(&line);
}

t_lgt	*create_light(int fd)
{
	char	*line;
	t_lgt	*light;

	error((int)(light = (t_lgt*)malloc(sizeof(t_lgt))));
	get_next_line(fd, &line);
	light->pos = parse_vector(line);
	ft_strdel(&line);
	get_next_line(fd, &line);
	light->hex = ft_atoi_base(line, 16);
	ft_strdel(&line);
	light->color = hex_to_color(light->hex);
	light->next = NULL;
	return (light);
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
	obj->scale = ft_atof(ft_strstr(line, "=") + 1);
	ft_strdel(&line);
	get_next_line(fd, &line);
	(obj->hex = ft_atoi_base(line, 16)) ? ft_strdel(&line) : 0;
	obj->color = hex_to_color(obj->hex);
	ft_strdel(&line);
	get_next_line(fd, &line);
	obj->mat.ambient = ft_atof(ft_strstr(line, "=") + 1);
	ft_strdel(&line);
	get_next_line(fd, &line);
	obj->mat.diffuse = ft_atof(ft_strstr(line, "=") + 1);
	ft_strdel(&line);
	get_next_line(fd, &line);
	obj->mat.specular = ft_atof(ft_strstr(line, "=") + 1);
	ft_strdel(&line);
	get_next_line(fd, &line);
	obj->mat.shininess = ft_atof(ft_strstr(line, "=") + 1);
	ft_strdel(&line);
	obj->next = NULL;
	return (obj);
}
