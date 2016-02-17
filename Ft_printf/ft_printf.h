/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:57:50 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/17 14:01:17 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>

typedef struct	s_a
{
	char	flag;
	char	width;
	char	precision;
	char	mod;
	char	type;
	int		tlen;
	void	*arg;
}				t_a;

typedef struct	s_e
{
	va_list	ap;
	int		plen;
	int		tlen;
}				t_e;

#endif
