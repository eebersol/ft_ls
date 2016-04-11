/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 21:28:36 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/30 21:28:44 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_print_size(t_file *file)
{
	if (file->max_major || file->max_minor)
	{
		ft_padding(file->major, file->max_major);
		ft_putstr("    ");
		ft_padding(file->minor, file->max_minor);
	}
	ft_padding(file->size, file->max_size);
	ft_putstr(file->size);
}
