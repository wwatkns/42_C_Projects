/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:01:22 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/29 11:23:04 by wwatkins         ###   ########.fr       */
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

	printf("camera:\n");
	printf("	pos: (%f, %f, %f)\n", e->cam.pos.x, e->cam.pos.y, e->cam.pos.z);
	printf("	dir: (%f, %f, %f)\n", e->cam.dir.x, e->cam.dir.y, e->cam.dir.z);
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

	printf("light:\n");
	printf("	pos: (%f, %f, %f)\n", e->lgt.pos.x, e->lgt.pos.y, e->lgt.pos.z);
	printf("	color: %x\n", e->lgt.color);
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
		free(split[i]);
		i++;
	}
	free(split);
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
	obj->index = index;
	obj->next = NULL;

	printf("object:\n");
	printf("	type: %d\n", obj->type);
	printf("	pos: (%f, %f, %f)\n", obj->pos.x, obj->pos.y, obj->pos.z);
	printf("	dir: (%f, %f, %f)\n", obj->dir.x, obj->dir.y, obj->dir.z);
	printf("	size: (%f, %f, %f)\n", obj->size.x, obj->size.y, obj->size.z);
	printf("	color: %x\n", obj->color);
	index++;
	return (obj);
}
