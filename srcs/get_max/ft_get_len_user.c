/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_user.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 21:06:05 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/30 21:06:06 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

size_t		ft_get_len_user(t_list *list)
{
	t_file	*file;
	t_list	*cur;
	size_t	max_user;

	cur = list;
	max_user = 0;
	while (cur)
	{
		file = cur->content;
		if (ft_strlen(ft_strdup(
			getpwuid(file->my_stat.st_uid)->pw_name)) > max_user)
			max_user = ft_strlen(ft_strdup(
				getpwuid(file->my_stat.st_uid)->pw_name));
		cur = cur->next;
	}
	cur = list;
	while (cur)
	{
		file = cur->content;
		file->max_user = max_user;
		cur = cur->next;
	}
	return (max_user);
}

size_t		ft_get_len_num_user(t_list *list)
{
	t_file	*file;
	t_list	*cur;
	size_t	max_num_user;

	cur = list;
	max_num_user = 0;
	while (cur)
	{
		file = cur->content;
		if (ft_strlen(ft_strdup(
			getpwuid(file->my_stat.st_uid)->pw_name)) > max_num_user)
			max_num_user = ft_strlen(ft_strdup(
				getpwuid(file->my_stat.st_uid)->pw_name));
		cur = cur->next;
	}
	cur = list;
	while (cur)
	{
		file = cur->content;
		file->max_num_user = max_num_user;
		cur = cur->next;
	}
	return (max_num_user);
}
