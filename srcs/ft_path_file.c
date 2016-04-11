/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 15:12:26 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/24 15:12:28 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	*ft_join_name(char *path_name, char *name)
{
	char	*tmp;

	tmp = ft_strjoin(path_name, "/");
	return (ft_strjoin(tmp, name));
}
