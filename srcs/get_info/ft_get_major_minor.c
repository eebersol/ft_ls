/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_major_minor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 20:58:07 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/30 20:58:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_get_major_minor(t_file *file)
{
	file->major = ft_itoa(major(file->my_stat.st_rdev));
	file->minor = ft_itoa(minor(file->my_stat.st_rdev));
}
