/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 21:01:33 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/30 21:01:34 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static int		ft_check_valid_opt(t_env *env, int i)
{
	if (env->str[i] != 'l' && env->str[i] != 'R' && env->str[i] != 'r'
	&& env->str[i] != 'a' && env->str[i] != 't' && env->str[i] != '1'
	&& env->str[i] != 'd' && env->str[i] != 'i' && env->str[i] != 'g'
	&& env->str[i] != 'm' && env->str[i] != 'n')
		return (1);
	else
		return (0);
	return (0);
}

static void		ft_disable_opt(t_env *env)
{
	env->opt.l = 0;
	env->opt.g = 0;
	env->opt.m = 0;
	env->opt.n = 0;
}

void			ft_get_option(t_env *env)
{
	int	i;

	i = 1;
	while (env->str[0] && env->str[i] != '\0')
	{
		env->opt.l = (env->str[i] == 'l') ? 1 : env->opt.l;
		env->opt.m = (env->str[i] == 'l') ? 0 : env->opt.m;
		env->opt.r_bis = (env->str[i] == 'R') ? 1 : env->opt.r_bis;
		env->opt.r = (env->str[i] == 'r') ? 1 : env->opt.r;
		env->opt.a = (env->str[i] == 'a') ? 1 : env->opt.a;
		env->opt.t = (env->str[i] == 't') ? 1 : env->opt.t;
		env->opt.d = (env->str[i] == 'd') ? 1 : env->opt.d;
		env->opt.g = (env->str[i] == 'g') ? 1 : env->opt.g;
		env->opt.l = (env->str[i] == 'g') ? 1 : env->opt.l;
		env->opt.m = (env->str[i] == 'm') ? 1 : env->opt.m;
		env->opt.l = (env->str[i] == 'm') ? 0 : env->opt.l;
		env->opt.n = (env->str[i] == 'n') ? 1 : env->opt.n;
		env->opt.l = (env->str[i] == 'n') ? 1 : env->opt.l;
		env->opt.i = (env->str[i] == 'i') ? 1 : env->opt.i;
		if (env->str[i] == '1' && env->str[i + 1] == '\0')
			ft_disable_opt(env);
		if ((ft_check_valid_opt(env, i)) == 1)
			ft_illegal_option(env->str);
		i++;
	}
}
