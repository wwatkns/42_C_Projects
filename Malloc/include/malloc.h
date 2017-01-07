/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:54:41 by wwatkins          #+#    #+#             */
/*   Updated: 2017/01/07 13:54:47 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include "libft.h"
# include "libftprintf.h"

# include <unistd.h>
# include <sys/mman.h>
# include <sys/resource.h>

# define TINY 0
# define SMALL 1
# define LARGE 2

# define TINY_RES 64
# define SMALL_RES 1024

# define BNUM 1023

# define MMAP_PROT PROT_READ | PROT_WRITE
# define MMAP_FLAG MAP_ANON | MAP_PRIVATE

# define SIZE 0
# define NUM 1
# define RES 2

# define TYPE(n) (n <= SMALL_RES ? (n <= TINY_RES ? TINY : SMALL) : LARGE)
# define PTYP(t) (t == TINY ? "TINY" : (t == SMALL ? "SMALL" : "LARGE"))

typedef struct	s_zone
{
	size_t			type;
	size_t			block[BNUM];
	struct s_zone	*next;
}				t_zone;

# define HEADER_SIZE sizeof(t_zone)

/*
**	Main functions
*/

void			free(void *ptr);
void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
void			show_alloc_mem(void);

/*
**	Utils functions
*/

size_t			convert_to_pagesize(size_t x);
size_t			get_info(size_t type, int info);
size_t			get_block_index(t_zone *zone, void *ptr);
void			*get_block_addr(t_zone *zone, size_t index);
int				check_addr(t_zone *zone, void *ptr);

#endif
