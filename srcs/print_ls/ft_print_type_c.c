/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 21:28:36 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/30 21:28:44 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_print_type_c(t_file *file)
{
	ft_putchar(' ');
	ft_padding(file->major, file->max_major);
	ft_putstr(file->major);
	ft_putchar(',');
	ft_putchar(' ');
	ft_padding(file->minor, file->max_minor);
	ft_putstr(file->minor);
}
