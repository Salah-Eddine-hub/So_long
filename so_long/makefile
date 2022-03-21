# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 16:27:19 by sharrach          #+#    #+#              #
#    Updated: 2022/03/21 23:24:07 by sharrach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	so_long

HEADER =	so_long.h

SRCS =	so_long.c\
		read_map.c\
		get_next_line.c\
		get_next_line_utils.c\
		ft_strdup.c   

OBJS =	$(SRCS:.c=.o)

CC =	cc

CFLAGS =	-Wall -Wextra -Werror

RM =	rm -f

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME):	$(OBJS) $(HEADER)
			make -C libft
			$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit libft/libft.a -o $(NAME)

all : $(NAME)

clean :
		make clean -C libft
		$(RM) $(NAME)

fclean :	clean
			make fclean -C libft
			$(RM) $(OBJS)

re :	fclean all