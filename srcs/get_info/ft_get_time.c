/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 20:58:55 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/30 20:59:50 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_get_time(t_file *file)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	file->date = ctime(&file->my_stat.st_mtime);
	if (((time(NULL) - file->my_stat.st_mtime) > 15768000)
		|| ((time(NULL) - file->my_stat.st_mtime) < 0))
	{
		tmp = ft_strnew(13);
		tmp = ft_strsub(file->date, 4, 9);
		tmp[6] = ' ';
		tmp[7] = ' ';
		tmp[8] = '\0';
		ft_strcat(tmp, ft_strsub(file->date, 20, 23));
		tmp[12] = '\0';
		file->date = tmp;
	}
	else
		file->date = ft_strsub(file->date, 4, 12);
}
