/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm_otool.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 11:03:40 by wwatkins          #+#    #+#             */
/*   Updated: 2017/03/07 19:09:38 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_OTOOL_H
# define FT_NM_OTOOL_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/mman.h>

# include <ar.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <mach-o/ranlib.h>

# include "libft.h"
# include "libftprintf.h"

typedef struct	s_symbol
{
	uint8_t		n_sect;
	uint8_t		n_type;
	uint64_t	n_value;
	uint32_t	fileoff;
}				t_symbol;

typedef struct	s_section
{
	char		sectname[16];
	char		segname[16];
	uint32_t	offset;
	uint32_t	size;
	uint64_t	addr;
}				t_section;

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

typedef struct	s_ran
{
	uint32_t	ran_off;
	char		*name;
	void		*obj;
}				t_ran;

typedef struct	s_info
{
	uint8_t		swap;
	uint8_t		sys;
	uint8_t		prog;
	uint32_t	magic;
	uint32_t	ncmds;
	uint32_t	header_offset;
	uint32_t	argc;
	char		*path;
	t_list		*list;
	t_list		*slist;
	t_list		*rlist;
}				t_info;

# define X86 0x0
# define X64 0x1
# define NM 0x2
# define OTOOL 0x3

# define ERR_FORM "%s: the file was not recognized as a valid object file.\n"
# define ERR_PERM "%s: Permission denied or incorrect file.\n"
# define ERR_MMAP "%s: mmap allocation failed.\n"
# define ERR_ARGC "%s: at least one file must be specified.\n"
# define ERR_DIRC "%s: Is a directory.\n"

/*
**  core.c
*/
void			core(void *file, t_info *info);
void			decode(void *file, t_info *info);
void			*mmap_file(char *path, struct stat *sb);
int				munmap_file(void *file, off_t st_size);
void			error(char *error_msg, char *path);

/*
**  magic.c
*/
int				is_magic(uint32_t magic);
int				is_magic_64(uint32_t magic);
int				is_fat(uint32_t magic);
int				is_ar(void *file);
int				is_swap(uint32_t magic);

/*
**  mach.c
*/
void			decode_command(void *file, t_info *info);

/*
**  mach_x64.c
*/
void			decode_mach_x64(void *file, t_info *info);
void			decode_segment_x64(void *file, int offset, t_info *info);
void			decode_symbol_table_x64(void *file, int offset, t_info *info);

/*
**  mach_x86.c
*/
void			decode_mach_x86(void *file, t_info *info);
void			decode_segment_x86(void *file, int offset, t_info *info);
void			decode_symbol_table_x86(void *file, int offset, t_info *info);

/*
**  utils.c
*/
uint32_t		swap_uint32(uint32_t val);
t_symbol		*new_symbol(uint8_t sec, uint8_t typ, uint64_t v, uint32_t off);
t_section		*new_section(char *seg, char *sec, uint32_t off, uint32_t size);
void			bubble_sort(void *file, t_list *head);
int				swap(t_list *a, t_list *b);

/*
**  fat.c
*/
void			decode_fat(void *file, t_info *info);

/*
**	ar.c
*/
void			decode_ar(void *file, t_info *info);

/*
**	list.c
*/
void			list_push_head(t_list **head, void *data, uint32_t bytes);
void			list_push_tail(t_list **head, void *data, uint32_t bytes);
void			list_delete(t_list **head);

/*
**	output.c
*/
void			output_nm(void *file, t_info *info);
void			output_otool(void *file, t_info *info);
void			print_nm(char *name, char type, uint64_t n_value, uint8_t sys);
void			print_otool(void *file, t_list *current, uint8_t sys);
void			print_nchar(char c, int n);

/*
**	symbol.c
*/
char			get_symbol_type(t_list *current, t_info *info);
char			get_symbol_section(uint8_t n_sect, t_info *info);

#endif
