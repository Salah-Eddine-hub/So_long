# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 16:27:19 by sharrach          #+#    #+#              #
#    Updated: 2022/04/15 14:52:34 by sharrach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		so_long

HEADER =	so_long.h

SRCS =		GetNextLine/get_next_line.c\
			GetNextLine/get_next_line_utils.c\
			read_map.c\
			check_map.c\
			movement.c\
			exit_program.c\
			so_long.c

OBJS =		$(SRCS:.c=.o)

CC =		cc

CFLAGS =	-Wall -Wextra -Werror

RM =		rm -f

%.o: %.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME):	$(OBJS) $(HEADER)
			make -C libft
			make -C ft_printf
			$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit libft/libft.a ft_printf/libftprintf.a -o $(NAME)

all : 		$(NAME)

clean :
			make clean -C libft
			make clean -C ft_printf
			$(RM) $(NAME)

fclean :	clean
			make fclean -C libft
			make fclean -C ft_printf
			$(RM) $(OBJS)

re :		fclean all

.PHONY:		all clean fclean re
