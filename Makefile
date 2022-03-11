# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 12:40:18 by ldinaut           #+#    #+#              #
#    Updated: 2022/03/11 14:21:35 by ldinaut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRCS	=	srcs/pipex.c \
			srcs/ft_split.c \
			srcs/ft_free.c \
			srcs/libft_subsitute.c \
			srcs/pipex_utils.c

SRCSBONUS	=	bonus/pipex_bonus.c \
				bonus/pipex_utils_bonus.c \
				bonus/libft_substitute_bonus.c \
				bonus/ft_split.c \
				bonus/ft_free.c

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -g -I./includes

OBJS	=	$(SRCS:%.c=%.o)

OBJSBONUS	=	$(SRCSBONUS:%.c=%.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		make -C ft_printf
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Lft_printf -lftprintf

bonus	:	$(OBJSBONUS)
		make -C ft_printf
		$(CC) $(CFLAGS) -o $(NAME) $(OBJSBONUS) -Lft_printf -lftprintf

clean	:
		make -C ft_printf clean
		rm -rf $(OBJS) $(OBJSBONUS)

fclean	:	clean
		make -C ft_printf fclean
		rm -rf $(NAME)

re		:	fclean all

.PHONY: all clean fclean re bonus
