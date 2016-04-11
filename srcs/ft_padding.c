/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 21:19:56 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/30 21:19:57 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_padding(char *name, size_t max)
{
	int		spaces;

	spaces = (max - ft_strlen(name));
	while (spaces > 0)
	{
		ft_putchar(' ');
		spaces--;
	}
}
