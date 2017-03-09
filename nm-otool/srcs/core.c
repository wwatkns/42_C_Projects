/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:07:38 by wwatkins          #+#    #+#             */
/*   Updated: 2017/03/07 18:46:46 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	error(char *error_msg, char *path)
{
	ft_printf(error_msg, path);
	exit(0);
}

void	*mmap_file(char *path, struct stat *sb)
{
	int		fd;
	void	*file;

	if ((fd = open(path, O_RDONLY)) == -1)
		error(ERR_PERM, path);
	if ((fstat(fd, sb)) == -1)
		return (NULL);
	if (sb->st_size == 0)
		error(ERR_FORM, path);
	if ((S_ISDIR(sb->st_mode)) == 1)
		error(ERR_DIRC, path);
	file = mmap(0, sb->st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (file == MAP_FAILED)
		error(ERR_MMAP, path);
	if ((close(fd)) == -1)
		return (NULL);
	return (file);
}

int		munmap_file(void *file, off_t st_size)
{
	if ((munmap(file, st_size)) == -1)
		return (0);
	return (1);
}

void	decode(void *file, t_info *info)
{
	if (is_magic(info->magic))
		decode_mach_x86(file, info);
	else if (is_magic_64(info->magic))
		decode_mach_x64(file, info);
	else if (is_fat(info->magic))
	{
		decode_fat(file, info);
		return ;
	}
	else
		error(ERR_FORM, info->path);
	bubble_sort(file, info->list);
	info->prog == NM ? output_nm(file, info) : output_otool(file, info);
}

void	core(void *file, t_info *info)
{
	info->list = NULL;
	info->slist = NULL;
	info->magic = *(int*)file;
	info->swap = (is_swap(info->magic) ? 1 : 0);
	if (!is_ar(file))
		decode(file, info);
	else
		decode_ar(file, info);
}
