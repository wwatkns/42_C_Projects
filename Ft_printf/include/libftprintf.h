/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:44:38 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/22 14:13:57 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <locale.h>
# include <limits.h>

typedef struct	s_flg
{
	int			pl;
	int			mn;
	int			sp;
	int			di;
	int			zr;
}				t_flg;

typedef struct	s_prc
{
	int			pt;
	int			prec;
}				t_prc;

typedef struct	s_mod
{
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			j;
	int			z;
}				t_mod;

typedef struct	s_a
{
	t_flg		flag;
	t_prc		prec;
	t_mod		mod;
	long int	width;
	char		type;
}				t_a;

typedef struct	s_e
{
	va_list		ap;
	int			alen;
	int			plen;
}				t_e;

int				ft_printf(const char *restrict format,
				...) __attribute__((format(printf,1,2)));

/*
**	parse format functions
*/

int				parse_format(const char *format, t_a *arg, t_e *e);
int				get_flags(const char *format, int i, t_a *arg);
int				get_mod(const char *format, int i, t_a *arg);
int				get_prec(const char *format, int i, t_a *arg);
int				get_type(const char *format, int i, t_a *arg);
int				get_width(const char *format, int i, t_a *arg);
int				is_mod(char md);
int				is_flag(char fl);
int				is_type(char ty);

/*
**	print arg functions
*/

int				print_arg(t_e *e, t_a *arg);
void			print_arg_percent(t_e *e, t_a *arg, int *i);
void			print_arg_int(t_e *e, t_a *arg, int *i);
void			print_arg_unsigned(t_e *e, t_a *arg, int *i);
void			print_arg_char(t_e *e, t_a *arg, int *i);
void			print_arg_str(t_e *e, t_a *arg, int *i);
void			print_arg_base(t_e *e, t_a *arg, int *i);
void			print_arg_ptr(t_e *e, t_a *arg, int *i);

/*
**	errors check functions
*/

int				check_err(t_a *arg);
int				check_zero(t_a *arg);
int				check_space(t_a *arg);
int				check_diez(t_a *arg);
int				check_plus(t_a *arg);

/*
**	utils functions
*/

int				nbr_len(long long int n);
int				nbr_len_unsigned(unsigned long long int n);
int				nbr_len_base(long n, const int base);
int				nbr_binary(unsigned int v);
int				str_len(const char *s);
int				print_int(long long int n, t_a *arg);
int				print_unsigned_int(unsigned long long int n,
				char pad, t_a *arg);
int				print_char(char c);
int				print_str(const char *s, t_a *arg);
int				print_wchar_t(wchar_t c);
int				print_str_wchar_t(const wchar_t *s, t_a *arg);
int				print_base(t_a *arg, unsigned long long n, const int base,
				char maj);
int				print_mem(void *p, t_a *arg);

#endif
