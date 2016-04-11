/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ftype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 21:01:22 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/30 21:01:23 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_get_ftype(t_file *file)
{
	if (S_ISREG(file->my_stat.st_mode))
		file->type = '-';
	else if (S_ISDIR(file->my_stat.st_mode))
		file->type = 'd';
	else if (S_ISCHR(file->my_stat.st_mode))
		file->type = 'c';
	else if (S_ISBLK(file->my_stat.st_mode))
		file->type = 'b';
	else if (S_ISFIFO(file->my_stat.st_mode))
		file->type = 'f';
	else if (S_ISSOCK(file->my_stat.st_mode))
		file->type = 's';
	else if (S_ISLNK(file->my_stat.st_mode))
		file->type = 'l';
}
