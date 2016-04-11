/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_date.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 21:06:22 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/30 21:06:23 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

size_t	ft_get_len_date(t_list *list)
{
	t_file		*file;
	t_list		*cur;
	size_t		max_date;

	cur = list;
	max_date = 0;
	while (cur)
	{
		file = cur->content;
		if (ft_strlen(ft_strsub((
			ctime(&file->my_stat.st_mtime)), 4, 12)) > max_date)
			max_date = ft_strlen(ft_strsub((
				ctime(&file->my_stat.st_mtime)), 4, 12));
		cur = cur->next;
	}
	cur = list;
	while (cur)
	{
		file = cur->content;
		file->max_date = max_date;
		cur = cur->next;
	}
	return (max_date);
}
