# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 16:27:19 by sharrach          #+#    #+#              #
#    Updated: 2022/03/15 17:05:36 by sharrach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	so_long

HEADER =	so_long.h

SRCS =	movesquare.c

OBJS =	$(SRCS:.c=.o)

CC =	gcc

CFLAGS =	-Wall -Wextra -Werror

RM =	rm -f

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME):	$(OBJS) $(HEADER)
			$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all : $(NAME)

clean :
		$(RM) $(NAME)

fclean :	clean
			$(RM) $(OBJS)

re :	fclean all