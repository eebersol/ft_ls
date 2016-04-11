/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_group.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 21:06:14 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/30 21:06:15 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

size_t	ft_get_len_group(t_list *list)
{
	t_file	*file;
	t_list	*cur;
	size_t	max_group;

	cur = list;
	max_group = 0;
	while (cur)
	{
		file = cur->content;
		if (ft_strlen(ft_strdup(
			getgrgid(file->my_stat.st_gid)->gr_name)) > max_group)
			max_group = ft_strlen(ft_strdup(
				getgrgid(file->my_stat.st_gid)->gr_name));
		cur = cur->next;
	}
	cur = list;
	while (cur)
	{
		file = cur->content;
		file->max_group = max_group;
		cur = cur->next;
	}
	return (max_group);
}

size_t	ft_get_len_num_group(t_list *list)
{
	t_file	*file;
	t_list	*cur;
	size_t	max_num_group;

	cur = list;
	max_num_group = 0;
	while (cur)
	{
		file = cur->content;
		if (ft_strlen(ft_strdup(
			getgrgid(file->my_stat.st_gid)->gr_name)) > max_num_group)
			max_num_group = ft_strlen(ft_strdup(
				getgrgid(file->my_stat.st_gid)->gr_name));
		cur = cur->next;
	}
	cur = list;
	while (cur)
	{
		file = cur->content;
		file->max_num_group = max_num_group;
		cur = cur->next;
	}
	return (max_num_group);
}
