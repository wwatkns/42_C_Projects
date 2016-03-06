/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 16:10:01 by wwatkins          #+#    #+#             */
/*   Updated: 2016/03/06 16:40:40 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*load_source(const char *file_name)
{
	char	*str;
	char	*line;
	int		fd;

	ft_error((int)(str = (char*)malloc(sizeof(char))));
	ft_error((fd = open(file_name, O_RDWR)));
	while (get_next_line(fd, &line) > 0)
	{
		str = ft_strjoin(line, str);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (str);
}

GLuint	set_shader(GLenum type, const char *file_name)
{
	GLuint	shader;
	char	*str;

	shader = glCreateShader(type);
	str = load_source(file_name);
	glShaderSource(shader, 1, (const GLchar**)&str, NULL);
	glCompileShader(shader);
	ft_strdel(&str);
	return (shader);
}

GLuint	set_program(GLuint shader)
{
	GLuint	program;

	program = glCreateProgram();
	glAttachShader(program, shader);
	glLinkProgram(program);
	return (program);
}
