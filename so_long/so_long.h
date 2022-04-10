/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:02:32 by sharrach          #+#    #+#             */
/*   Updated: 2022/04/09 23:27:29 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# define BUFFER_SIZE 1

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include <fcntl.h>
#include <mlx.h>
#include "libft/libft.h"
#include "GetNextLine/get_next_line.h"

char	*get_next_line(int fd);
size_t	ft_arrlen(char **arr);
char	*ft_strdup(const char *src);
char	*ft_stradd(char const *s1, char const *s2);
char	**read_map(char *file);
int		map_checker(char **map);


#endif