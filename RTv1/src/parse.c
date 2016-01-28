/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:01:22 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/28 16:40:53 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_scene(t_env *e)
{
	int		fd;
	char	*line;

	error((fd = open(e->rg.file_name, O_RDWR)));
	ft_strdel(&e->arg.file_scene);
	while (get_next_line(fd, &line) > 0)
	{
		!ft_strcmp(line, "object") : create_object(fd) : 0;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	error((close(fd) + 1));
}

t_obj	create_object(int fd)
{
	static int	index = 0;
	char		*line;
	t_obj		*obj;

	obj = (t_obj*)malloc(sizeof(t_obj));
	get_next_line(fd, &line);
	(e->obj.pos = parse_vector(line)) ? ft_strdel(&line) : 0;
	get_next_line(fd, &line);
	(e->obj.dir = parse_vector(line)) ? ft_strdel(&line) : 0;
	get_next_line(fd, &line);
	(e->obj.size = parse_vector(line)) ? ft_strdel(&line) : 0;
	get_next_line(fd, &line);
	!ft_strstr(line, "plane") ? e->obj.type = PLANE : 0;
	!ft_strstr(line, "cylinder") ? e->obj.type = CYLINDER : 0;
	!ft_strstr(line, "sphere") ? e->obj.type = SPHERE : 0;
	!ft_strstr(line, "cone") ? e->obj.type = CONE : 0;
	ft_strdel(&line);
	get_next_line(fd, &line);
	(e->obj.color = ft_atoi_base(line, 16)) ? ft_strdel(&line) : 0;
	e->obj.index = index;
	e->obj.next == NULL;
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
	while (split[i] != NULL)
	{
		!ft_striterr(split[i], ft_isdigit) ? n++ : 0;
		n == 1 ? vec3.x = ft_atoi(split[i]) : 0;
		n == 2 ? vec3.y = ft_atoi(split[i]) : 0;
		n == 3 ? vec3.z = ft_atoi(split[i]) : 0;
		free(split[i]);
		i++;
	}
	free(split);
	return (vec3);
}
