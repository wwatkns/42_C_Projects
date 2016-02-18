/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:57:50 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/18 10:55:42 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>

typedef struct	s_flg
{
	short	s;
	short	m;
	short	p;
	short	d;
	short	z;
}				t_flg;

typedef struct	s_prc
{
	short	p;
	int		prec;
}				t_prc;

typedef struct	s_mod
{
	short	h;
	short	hh;
	short	l;
	short	ll;
	short	j;
	short	z;
}				t_mod;

typedef struct	s_arg
{
	t_flg	flag;
	t_prc	prec;
	t_mod	modi;
	int		width;
	char	type;
	void	*p;
}				t_arg;

typedef struct	s_global
{
	t_arg	arg;
	va_list	ap;
	int		plen;
	int		alen;
}				t_global;

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

int		parse_format(t_global *e, const char *format);

int		get_flags(t_global *e, const char *format, int i);
int		get_width(t_global *e, const char *format, int i);
int		get_prec(t_global *e, const char *format, int i);
int		get_mod(t_global *e, const char *format, int i);
int		get_type(t_global *e, const char *format, int i);

#endif
