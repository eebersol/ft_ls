/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_total.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 20:58:21 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/30 20:58:23 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		ft_get_total(t_list *list)
{
	t_file	*file;
	int		total;

	total = 0;
	while (list)
	{
		file = list->content;
		total += file->my_stat.st_blocks;
		list = list->next;
	}
	return (total);
}
