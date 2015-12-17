/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 10:13:25 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/17 10:02:47 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <libft.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFF_SIZE 32

int	get_next_line(int const fd, char **line);

#endif
