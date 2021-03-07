# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 20:30:59 by tyou              #+#    #+#              #
#    Updated: 2021/03/08 00:33:34 by tyou             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		=	ft_printf.c \
				utils_a.c \
				utils_b.c \
				print_int.c \
				print_char.c \
				print_hex.c
				
OBJS		= $(SRCS:c=o)
RM			= rm -f
AR			= ar rc
CC			= gcc
FLAGS		= -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $(OBJS)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

re : fclean all
