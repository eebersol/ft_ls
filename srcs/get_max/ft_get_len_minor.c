/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_minor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 21:05:45 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/30 21:05:46 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		ft_get_len_minor(t_list *list)
{
	t_file	*file;
	t_list	*cur;
	size_t	max_minor;

	cur = list;
	max_minor = 0;
	while (cur)
	{
		file = cur->content;
		if ((file->type == 'c' || file->type == 'b')
			&& (ft_strlen(file->minor) > max_minor))
			max_minor = ft_strlen(file->minor);
		cur = cur->next;
	}
	cur = list;
	while (cur)
	{
		file = cur->content;
		file->max_minor = max_minor;
		cur = cur->next;
	}
	return (max_minor);
}
