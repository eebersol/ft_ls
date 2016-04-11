/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_opt_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 21:28:36 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/30 21:28:44 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_print_opt_n(t_file *file)
{
	ft_putchar(' ');
	ft_putstr(file->num_user);
	ft_putstr("  ");
	ft_putstr(file->num_group);
	ft_putstr("  ");
	ft_padding(file->size, file->max_size);
	ft_putstr(file->size);
}
