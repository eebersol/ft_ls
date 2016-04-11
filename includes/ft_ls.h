/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 20:17:42 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/07 18:14:53 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <pwd.h>
# include <grp.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <dirent.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <time.h>
# include "../libft/includes/libft.h"

typedef struct s_env	t_env;

typedef struct		s_file{
	char			*name;
	size_t			max_name;
	char			*user_name;
	size_t			max_user;
	char			*group_name;
	size_t			max_group;
	char			*path;
	char			type;
	char			*date;
	size_t			max_date;
	char			*right;
	char			*link;
	int				max_link;
	struct s_file	*next;
	struct s_env	*env;
	struct dirent	*read_file;
	int				exists;
	char			*size;
	int				max_size;
	char			*major;
	size_t			max_major;
	char			*minor;
	int				max_minor;
	int				block;
	char			*inoeud;
	int				max_inoeud;
	char			*num_group;
	int				max_num_group;
	char			*num_user;
	int				max_num_user;
	char			*spe_link;
	int				dir_empty;
	struct stat		my_stat;
	struct passwd	my_passwd;
}					t_file;

typedef struct		s_opt{
	char			*str;
	int				l;
	int				r_bis;
	int				r;
	int				a;
	int				t;
	int				d;
	int				i;
	int				g;
	int				m;
	int				n;
}					t_opt;

struct				s_env{
	char			*str;
	struct s_list	*list_errors;
	struct s_list	*list_non_folders;
	struct s_list	*list_folders;
	struct s_file	*file;
	struct s_opt	opt;
	int				first_folder_processed;
	int				nb_files;
	int				its_error;
};

int					ft_get_len_inoeud(t_list *list);
void				ft_get_spe_link(t_file *file);
int					ft_get_bonus_opt(t_env *env, int i);
void				ft_get_inoeud(t_file *file);
void				ft_get_option(t_env *env);
void				ft_get_ftype(t_file *file);
void				ft_get_right(t_file *file);
void				ft_get_major_minor(t_file *file);
void				ft_get_user(t_file *file);
void				ft_get_group(t_file *file);
void				ft_get_link(t_file *file);
void				ft_get_time(t_file *file);
void				ft_get_size(t_file *file);
void				ft_get_numeric_group(t_file *file);
void				ft_get_numeric_user(t_file *file);
int					ft_get_total(t_list *list);
char				ft_get_uid(struct stat stat);
char				ft_get_gid(struct stat stat);
int					ft_get_exists(char *filename);
size_t				ft_get_len_num_user(t_list *list);
size_t				ft_get_len_num_group(t_list *list);
size_t				ft_get_len_num_user(t_list *list);
int					ft_get_len_link(t_list *list);
int					ft_get_len_size(t_list *list);
int					ft_get_len_major(t_list *list);
int					ft_get_len_minor(t_list *list);
size_t				ft_get_len_name(t_list *list);
size_t				ft_get_len_user(t_list *list);
size_t				ft_get_len_group(t_list *list);
size_t				ft_get_len_date(t_list *list);
void				ft_get_all_len(t_list *list);
void				show_file(t_list *elem);
void				show_folder(t_list *elem);
void				ft_open_dir(t_list **list, t_file *file);
int					ft_no_dot_files(t_list *list);
void				ft_display_opt(t_env *env, t_file *file);
char				ft_seek_illegal_option(char *name);
void				ft_error_no_such_file(char *name);
void				ft_illegal_option(char *name);
void				ft_permission_denied(char *name);
void				ft_bad_fd(char *name);
void				ft_print_opt_n(t_file *file);
void				ft_print_type_c(t_file *file);
void				ft_print_info(t_file *file);
void				ft_print_size(t_file *file);
void				ft_print_total(t_list *list);
void				ft_init_option(t_opt *opt);
t_env				*ft_init_env(void);
t_file				*ft_init_file(t_env *env, char *name, char *path);
void				ft_print_info(t_file *file);
void				ft_print_info2(t_file *file);
void				ft_print_opt_l(t_file *file);
void				ft_print_opt_n(t_file *file);
void				ft_print_size(t_file *file);
void				ft_print_total(t_list *list);
void				ft_print_type_c(t_file *file);
void				ft_print_spe_link(t_file *file);
char				*ft_join_name(char *path_name, char *name);
void				ft_padding(char *name, size_t max);
int					ft_sort_lexico(t_list *list_a, t_list *list_b);
int					ft_sort_t(t_list *list_a, t_list *list_b);
void				ft_sort_files(t_env *env, t_list **list);

#endif
