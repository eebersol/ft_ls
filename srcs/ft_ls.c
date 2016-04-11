/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 20:58:48 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/14 20:58:50 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	main_create_list(t_env *env, t_file *file)
{
	if (!file->exists)
		ft_lstadd(&env->list_errors, ft_lstnew(file, (sizeof(t_file))));
	else if (file->type == 'd' && env->opt.d != 1)
		ft_lstadd(&env->list_folders, ft_lstnew(file, (sizeof(t_file))));
	else
		ft_lstadd(&env->list_non_folders, ft_lstnew(file,
			(sizeof(t_file))));
	env->nb_files++;
}

int		main_options(t_env *env, int i, int ac, char **av)
{
	while (i < ac && av[i] && av[i][0] == '-' && av[i][1] != '\0'
		&& ft_strcmp(av[i], "--") != 0)
	{
		env->str = av[i];
		ft_get_option(env);
		i++;
	}
	if (av[i] && ft_strcmp(av[i], "--") == 0)
		i++;
	return (i);
}

void	main_add_files(t_env *env, int i, int ac, char **av)
{
	t_file	*file;

	if (i == ac && env->opt.d != 1)
	{
		file = ft_init_file(env, ft_strdup("."), ft_strdup("."));
		ft_lstadd(&env->list_folders, ft_lstnew(file, (sizeof(t_file))));
		env->nb_files = 1;
	}
	if (i == ac && env->opt.d == 1)
	{
		file = ft_init_file(env, ft_strdup("."), ft_strdup("."));
		ft_lstadd(&env->list_non_folders, ft_lstnew(file, (sizeof(t_file))));
	}
	while (i < ac)
	{
		env->str = av[i];
		file = ft_init_file(env, ft_strdup(av[i]), ft_strdup(av[i]));
		main_create_list(env, file);
		i++;
	}
}

int		main(int ac, char **av)
{
	t_env	*env;
	int		i;

	env = ft_init_env();
	i = 1;
	ft_init_option(&env->opt);
	i = main_options(env, i, ac, av);
	main_add_files(env, i, ac, av);
	ft_get_all_len(env->list_non_folders);
	ft_sort_files(env, &env->list_non_folders);
	ft_sort_files(env, &env->list_folders);
	env->its_error = 1;
	ft_sort_files(env, &env->list_errors);
	ft_lstiter(env->list_errors, &show_file);
	env->its_error = 0;
	ft_lstiter(env->list_non_folders, &show_file);
	ft_lstiter(env->list_folders, &show_folder);
}
