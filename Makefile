# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 12:40:18 by ldinaut           #+#    #+#              #
#    Updated: 2022/03/04 18:11:38 by ldinaut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRCS	=	srcs/pipex.c \
			srcs/ft_split.c \
			srcs/ft_free.c \
			srcs/libft_subsitute.c \
			srcs/pipex_utils.c

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -g -I./includes

OBJS	=	$(SRCS:%.c=%.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		make -C ft_printf
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Lft_printf -lftprintf

clean	:
		make -C ft_printf clean
		rm -rf $(OBJS)

fclean	:	clean
		make -C ft_printf fclean
		rm -rf $(NAME)

re		:	fclean all

.PHONY: all clean fclean re
