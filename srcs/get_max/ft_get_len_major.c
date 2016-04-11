/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_major.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 21:05:30 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/30 21:05:31 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		ft_get_len_major(t_list *list)
{
	t_file		*file;
	t_list		*cur;
	size_t		max_major;

	cur = list;
	max_major = 0;
	while (cur)
	{
		file = cur->content;
		if ((file->type == 'c' || file->type == 'b') && (ft_strlen(
			file->major) > max_major))
			max_major = ft_strlen(file->major);
		cur = cur->next;
	}
	cur = list;
	while (cur)
	{
		file = cur->content;
		file->max_major = max_major;
		cur = cur->next;
	}
	return (max_major);
}
