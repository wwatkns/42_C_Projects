/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:04:14 by wwatkins          #+#    #+#             */
/*   Updated: 2016/11/23 17:04:16 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROTOTYPE_H
# define FT_PROTOTYPE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

# define BUF_SIZE 2048

int		ft_return_error(int argc);
int		ft_display_file(char **argv);
int		ft_strlen(char *str);
void	ft_putstr_fd(int fd, char *str);

#endif
