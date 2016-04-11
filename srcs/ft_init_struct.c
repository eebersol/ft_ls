/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 20:37:26 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/14 20:37:28 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_init_option(t_opt *opt)
{
	opt->l = 0;
	opt->r_bis = 0;
	opt->r = 0;
	opt->a = 0;
	opt->t = 0;
	opt->d = 0;
	opt->i = 0;
	opt->g = 0;
	opt->m = 0;
	opt->n = 0;
}

t_env	*ft_init_env(void)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->str = NULL;
	env->list_errors = NULL;
	env->list_non_folders = NULL;
	env->list_folders = NULL;
	env->first_folder_processed = 0;
	env->its_error = 0;
	return (env);
}

t_file	*ft_init_file(t_env *env, char *name, char *path)
{
	t_file	*file;

	file = (t_file*)malloc(sizeof(t_file));
	file->exists = (lstat(path, &file->my_stat) != -1);
	file->name = name;
	file->path = path;
	file->env = env;
	file->next = NULL;
	file->read_file = NULL;
	if (!file->exists)
		return (file);
	ft_get_user(file);
	ft_get_group(file);
	ft_get_numeric_group(file);
	ft_get_numeric_user(file);
	ft_get_time(file);
	ft_get_right(file);
	ft_get_size(file);
	ft_get_link(file);
	ft_get_ftype(file);
	ft_get_inoeud(file);
	ft_get_spe_link(file);
	ft_get_major_minor(file);
	return (file);
}
