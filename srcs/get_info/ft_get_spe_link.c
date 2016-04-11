/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_spe_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 15:12:26 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/24 15:12:28 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_get_spe_link(t_file *file)
{
	int	ret;

	file->spe_link = (char *)malloc(sizeof(char *) * 256);
	ret = 0;
	if ((ret = readlink(file->path, file->spe_link, 256)) != -1)
		return ;
}
