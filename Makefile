# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eebersol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/28 21:09:05 by eebersol          #+#    #+#              #
#    Updated: 2016/03/02 16:18:01 by eebersol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Define the program
NAME 	= ft_ls

_SRCS 	= 	ft_ls.c \
			ft_error.c \
			ft_init_struct.c \
			ft_sort_dir.c \
			ft_display.c \
			ft_path_file.c \
			ft_padding.c \
			get_info/ft_get_ftype.c \
			get_info/ft_get_group.c \
			get_info/ft_get_link.c \
			get_info/ft_get_major_minor.c \
			get_info/ft_get_option.c \
			get_info/ft_get_right.c \
			get_info/ft_get_size.c \
			get_info/ft_get_time.c \
			get_info/ft_get_total.c \
			get_info/ft_get_user.c \
			get_max/ft_get_all_len.c \
			get_max/ft_get_len_date.c \
			get_max/ft_get_len_group.c \
			get_max/ft_get_len_link.c \
			get_max/ft_get_len_major.c \
			get_max/ft_get_len_minor.c \
			get_max/ft_get_len_name.c \
			get_max/ft_get_len_size.c \
			get_max/ft_get_len_user.c \
			get_info/ft_get_inoeud.c \
			print_ls/ft_print_info.c \
			print_ls/ft_print_info2.c \
			print_ls/ft_print_opt_l.c \
			print_ls/ft_print_opt_n.c \
			print_ls/ft_print_size.c \
			print_ls/ft_print_total.c \
			print_ls/ft_print_type_c.c \
			print_ls/ft_print_spe_link.c \
			get_info/ft_get_exists.c \
			get_info/ft_get_spe_link.c \
			get_max/ft_get_len_inoeud.c

SRCS  	= $(addprefix srcs/,$(_SRCS))
LIBFT 	= -Llibft -lft -Ilibft
CFLAGS	= -Wall -Wextra -Werror
CC 		= gcc $(CFLAGS)

all		:$(NAME)

$(NAME)	:
	@make -C libft
	@$(CC) $(SRCS) -Iincludes -o $(NAME) $(LIBFT)
	@echo $(NAME) "Compiled"

clean	:
	@make fclean -C libft
	@/bin/rm -rf bin
	@echo "Clean all .o"

fclean	:
	@make fclean -C libft
	@/bin/rm -rf bin
	@/bin/rm -rf $(NAME)
	@echo "clean all .o .a"

re		: fclean all

.PHONY: all, clean, fclean, re
