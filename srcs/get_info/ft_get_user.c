/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_user.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 20:58:36 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/30 20:58:38 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_get_user(t_file *file)
{
	if ((getpwuid(file->my_stat.st_uid) != NULL))
		file->user_name = ft_strdup(getpwuid(file->my_stat.st_uid)->pw_name);
}

void	ft_get_numeric_user(t_file *file)
{
	if ((getpwuid(file->my_stat.st_uid) != NULL))
		file->num_user = ft_strdup(ft_itoa(file->my_stat.st_uid));
}
