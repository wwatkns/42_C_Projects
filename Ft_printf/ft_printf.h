/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:57:50 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/18 10:07:27 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>

typedef struct	s_arg
{
	char	flag;
	char	width;
	char	precision;
	char	mod;
	char	type;
	int		tlen;
	void	*p;
}				t_arg;

typedef struct	s_e
{
	t_arg	arg;
	va_list	ap;
	int		plen;
	int		tlen;
}				t_e;

int		ft_printf(const char *restrict format, ...);

int		print_int(long long int n);
int		print_unsigned_int(unsigned long long int n);

int		print_char(const char c);
int		print_wchar_t(const wchar_t c);

int		print_str(const char *s, int max);
int		print_str_wchar_t(const wchar_t *s, int max);

int		print_base(long n, const int base, char maj);
int		print_mem(unsigned int p);

int		nbr_len(long long int n);
int		str_len(const char *s);

int		parse_format();

#endif
