/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 17:09:53 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/24 17:09:56 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	show_file(t_list *elem)
{
	t_file	*file;

	file = elem->content;
	if (file->env->its_error == 0)
		file->env->first_folder_processed = 1;
	if (!file->exists)
		ft_error_no_such_file(file->name);
	if (file->env->opt.i && !file->env->opt.l)
	{
		ft_padding(file->inoeud, file->max_inoeud);
		ft_putstr(file->inoeud);
		ft_putchar(' ');
	}
	if (!file->env->opt.l && !file->env->opt.m && file->env->its_error != 1)
		ft_putendl(file->name);
	if (file->env->opt.m)
	{
		ft_putstr(file->name);
		if (elem->next != NULL)
			ft_putstr(", ");
		else
			ft_putchar('\n');
	}
	else if (file->env->opt.l)
		ft_print_opt_l(file);
}

int		ft_no_dot_files(t_list *list)
{
	t_file	*file;

	file = list->content;
	if (ft_strcmp(file->name, ".") == 0)
		return (0);
	if (ft_strcmp(file->name, "..") == 0)
		return (0);
	return (1);
}

void	show_folder(t_list *elem)
{
	t_file	*file;
	t_list	*list;

	list = NULL;
	file = elem->content;
	if (file->type != 'd')
		return ;
	if (file->env->first_folder_processed)
		ft_putchar('\n');
	if (file->env->nb_files > 1 || file->env->first_folder_processed)
	{
		ft_putstr(file->path);
		ft_putstr(":\n");
	}
	ft_open_dir(&list, file);
	if (file->right[0] != 'r')
		ft_permission_denied(file->name);
	if (file->env->opt.l && file->right[0] == 'r' && file->dir_empty == 1)
		ft_print_total(list);
	file->env->first_folder_processed = 1;
	ft_sort_files(file->env, &list);
	ft_get_all_len(list);
	ft_lstiter(list, &show_file);
	if (file->env->opt.r_bis)
		ft_lstiter_if(list, &show_folder, &ft_no_dot_files);
}

void	ft_open_dir(t_list **list, t_file *file)
{
	DIR		*rep;
	t_file	*new_file;

	rep = NULL;
	if ((rep = opendir(file->path)) == NULL)
	{
		ft_bad_fd(file->name);
		return ;
	}
	while ((file->read_file = readdir(rep)))
	{
		if (!(!file->env->opt.a && file->read_file->d_name[0] == '.'))
		{
			new_file = ft_init_file(file->env, ft_strdup(
				file->read_file->d_name),
			ft_join_name(file->path, file->read_file->d_name));
			ft_lstadd(list, ft_lstnew(new_file, (sizeof(t_file))));
			file->dir_empty = 1;
		}
	}
	closedir(rep);
}
