/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 21:05:13 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/30 21:05:14 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		ft_get_len_link(t_list *list)
{
	t_file	*file;
	t_list	*cur;
	int		max_link;

	cur = list;
	max_link = 0;
	while (cur)
	{
		file = cur->content;
		if (ft_len_int(file->my_stat.st_nlink) > max_link)
			max_link = ft_len_int(file->my_stat.st_nlink);
		cur = cur->next;
	}
	cur = list;
	while (cur)
	{
		file = cur->content;
		file->max_link = max_link;
		cur = cur->next;
	}
	return (max_link);
}
