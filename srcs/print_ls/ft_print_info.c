/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 21:28:36 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/30 21:28:44 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void		ft_print_opt_i(t_file *file)
{
	ft_padding(file->inoeud, file->max_inoeud);
	ft_putstr(file->inoeud);
	ft_putchar(' ');
}

void			ft_print_info(t_file *file)
{
	if (file->env->opt.i && file->env->opt.l)
		ft_print_opt_i(file);
	ft_putchar(file->type);
	ft_putstr(file->right);
	ft_putstr("  ");
	ft_padding(file->link, file->max_link);
	ft_putstr(file->link);
	if (!file->env->opt.g && !file->env->opt.n)
	{
		ft_putchar(' ');
		ft_putstr(file->user_name);
		ft_padding(file->user_name, file->max_user);
	}
	if (file->env->opt.n)
		ft_print_opt_n(file);
	else
	{
		if (file->env->opt.g)
			ft_putstr(" ");
		else
			ft_putstr("  ");
		ft_putstr(file->group_name);
		ft_padding(file->group_name, file->max_group);
		ft_putstr("  ");
	}
}
