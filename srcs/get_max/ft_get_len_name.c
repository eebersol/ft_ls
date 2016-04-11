/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 21:05:53 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/30 21:05:55 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

size_t		ft_get_len_name(t_list *list)
{
	t_file	*file;
	t_list	*cur;
	size_t	max_name;

	cur = list;
	max_name = 0;
	while (cur)
	{
		file = cur->content;
		if (ft_strlen(file->name) > max_name)
			max_name = ft_strlen(file->name);
		cur = cur->next;
	}
	cur = list;
	while (cur)
	{
		file = cur->content;
		file->max_name = max_name;
		cur = cur->next;
	}
	return (max_name);
}
