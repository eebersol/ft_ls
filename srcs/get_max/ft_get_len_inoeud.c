/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_inoeud.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 21:07:35 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/07 21:07:38 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		ft_get_len_inoeud(t_list *list)
{
	t_file		*file;
	t_list		*cur;
	int			max_inoeud;

	cur = list;
	max_inoeud = 0;
	while (cur)
	{
		file = cur->content;
		if (ft_len_int(file->my_stat.st_ino) > max_inoeud)
			max_inoeud = ft_len_int(file->my_stat.st_ino);
		cur = cur->next;
	}
	cur = list;
	while (cur)
	{
		file = cur->content;
		file->max_inoeud = max_inoeud;
		cur = cur->next;
	}
	return (max_inoeud);
}
