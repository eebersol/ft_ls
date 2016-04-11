/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 11:51:00 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/21 11:51:01 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		ft_sort_lexico(t_list *list_a, t_list *list_b)
{
	t_file	*file_a;
	t_file	*file_b;

	file_a = list_a->content;
	file_b = list_b->content;
	return (ft_strcmp(file_a->name, file_b->name) < 0);
}

int		ft_sort_t(t_list *list_a, t_list *list_b)
{
	t_file	*file_a;
	t_file	*file_b;

	file_a = list_a->content;
	file_b = list_b->content;
	if (file_a->my_stat.st_mtime == file_b->my_stat.st_mtime)
		return (file_a->my_stat.st_mtimespec.tv_nsec
			>= file_b->my_stat.st_mtimespec.tv_nsec);
	else
		return (file_a->my_stat.st_mtime >= file_b->my_stat.st_mtime);
}

void	ft_sort_files(t_env *env, t_list **list)
{
	(void)env;
	ft_insertion_sort(list, &ft_sort_lexico);
	if (env->opt.t == 1)
		ft_insertion_sort(list, &ft_sort_t);
	if (env->opt.r == 1 && env->its_error != 1)
		ft_lstrev(list);
}
