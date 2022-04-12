# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharrach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 12:16:17 by sharrach          #+#    #+#              #
#    Updated: 2021/12/09 12:16:20 by sharrach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

HEADER =	ft_printf.h

SRCS =	ft_printf.c\
		ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

cc = gcc

CFLAGS = -Wall -Wextra -Werror

RM		= rm -f

$(NAME):	$(OBJS) $(HEADER)
		ar rcs $(NAME) $(OBJS)

all:	$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re: fclean all
