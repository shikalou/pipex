# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 12:40:18 by ldinaut           #+#    #+#              #
#    Updated: 2022/03/01 19:12:00 by ldinaut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRCS	=	pipex.c \
			ft_split.c

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -g

OBJS	=	$(SRCS:%.c=%.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean	:
		rm -rf $(OBJS)

fclean	:	clean
		rm -rf $(NAME)

re		:	fclean all

.PHONY: all clean fclean re