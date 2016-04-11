/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_group.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 20:58:46 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/30 20:58:48 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_get_group(t_file *file)
{
	if ((getgrgid(file->my_stat.st_gid) != NULL))
		file->group_name = ft_strdup(getgrgid(file->my_stat.st_gid)->gr_name);
}

void	ft_get_numeric_group(t_file *file)
{
	if ((getgrgid(file->my_stat.st_gid) != NULL))
		file->num_group = ft_strdup(ft_itoa(file->my_stat.st_gid));
}
