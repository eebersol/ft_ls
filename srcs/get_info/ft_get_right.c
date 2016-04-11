/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 21:01:13 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/30 21:01:14 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_get_right(t_file *file)
{
	file->right = (char*)malloc(sizeof(char) * 9);
	file->right[0] = (file->my_stat.st_mode & S_IRUSR) ? 'r' : '-';
	file->right[1] = (file->my_stat.st_mode & S_IWUSR) ? 'w' : '-';
	file->right[2] = (file->my_stat.st_mode & S_IXUSR) ? 'x' : '-';
	if (file->right[2] == 'x' && (file->my_stat.st_mode & S_ISUID))
		file->right[2] = 's';
	else if (file->right[2] == '-' && (file->my_stat.st_mode & S_ISUID))
		file->right[2] = 'S';
	file->right[3] = (file->my_stat.st_mode & S_IRGRP) ? 'r' : '-';
	file->right[4] = (file->my_stat.st_mode & S_IWGRP) ? 'w' : '-';
	file->right[5] = (file->my_stat.st_mode & S_IXGRP) ? 'x' : '-';
	if (file->right[5] == 'x' && (file->my_stat.st_mode & S_ISGID))
		file->right[5] = 's';
	else if (file->right[5] == '-' && (file->my_stat.st_mode & S_ISGID))
		file->right[5] = 'S';
	file->right[6] = (file->my_stat.st_mode & S_IROTH) ? 'r' : '-';
	file->right[7] = (file->my_stat.st_mode & S_IWOTH) ? 'w' : '-';
	file->right[8] = (file->my_stat.st_mode & S_IXOTH) ? 'x' : '-';
	if (file->right[8] == 'x' && (file->my_stat.st_mode & S_ISVTX))
		file->right[8] = 't';
	else if (file->right[8] == '-' && (file->my_stat.st_mode & S_ISVTX))
		file->right[8] = 'T';
}
