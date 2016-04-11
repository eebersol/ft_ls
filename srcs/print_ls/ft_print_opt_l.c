/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_opt_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 21:28:36 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/30 21:28:44 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_print_opt_l(t_file *file)
{
	ft_print_info(file);
	if (file->type != 'c' && file->env->opt.l && !file->env->opt.n)
		ft_print_size(file);
	if (file->type == 'c')
		ft_print_type_c(file);
	ft_print_info2(file);
	if (file->type == 'l')
		ft_print_spe_link(file);
	else
		ft_putchar('\n');
}
