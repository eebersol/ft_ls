/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 19:48:31 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/02 16:15:18 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	ft_seek_illegal_option(char *name)
{
	int i;

	i = 1;
	while ((name[i] == 'l' || name[i] == 'R' || name[i] == 'r'
			|| name[i] == 'a' || name[i] == 't' || name[i] == '1'
			|| name[i] == 'd' || name[i] == 'i' || name[i] == 'g'
			|| name[i] == 'm' || name[i] == 'n'))
		i++;
	return (name[i]);
}

void	ft_error_no_such_file(char *name)
{
	ft_putstr_fd("ls: ", 2);
	if (name[0] == '\0')
	{
		ft_putstr_fd("fts_open", 2);
		ft_putendl_fd(": No such file or directory", 2);
		exit(1);
	}
	else
	{
		ft_putstr_fd(name, 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
}

void	ft_illegal_option(char *name)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_seek_illegal_option(name);
	if (name[0] == '-' || name[1] != '-')
		ft_putchar_fd(ft_seek_illegal_option(name), 2);
	else
		ft_putchar_fd(name[0], 2);
	ft_putendl("\nusage: ls [-Radgilmnrt1] [file...]");
	exit(1);
}

void	ft_permission_denied(char *name)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(name, 2);
	ft_putendl_fd(": Permission denied", 2);
}

void	ft_bad_fd(char *name)
{
	ft_putstr_fd("ls: ", 2);
	perror(name);
}
