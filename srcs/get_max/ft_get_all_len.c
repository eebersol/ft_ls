/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_all_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 21:06:35 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/30 21:06:36 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_get_all_len(t_list *list)
{
	ft_get_len_link(list);
	ft_get_len_size(list);
	ft_get_len_minor(list);
	ft_get_len_major(list);
	ft_get_len_name(list);
	ft_get_len_user(list);
	ft_get_len_group(list);
	ft_get_len_date(list);
	ft_get_len_num_group(list);
	ft_get_len_num_user(list);
	ft_get_len_inoeud(list);
}
