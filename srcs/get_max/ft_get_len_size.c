/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 21:05:22 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/30 21:05:23 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		ft_get_len_size(t_list *list)
{
	t_file		*file;
	t_list		*cur;
	int			max_size;

	cur = list;
	max_size = 0;
	while (cur)
	{
		file = cur->content;
		if (ft_len_int(file->my_stat.st_size) > max_size)
			max_size = ft_len_int(file->my_stat.st_size);
		cur = cur->next;
	}
	cur = list;
	while (cur)
	{
		file = cur->content;
		file->max_size = max_size;
		cur = cur->next;
	}
	return (max_size);
}
