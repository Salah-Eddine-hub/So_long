/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:02:32 by sharrach          #+#    #+#             */
/*   Updated: 2022/03/22 12:50:43 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# define BUFFER_SIZE 1

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include <fcntl.h>
#include <mlx.h>
#include "libft/libft.h"
#include "get_next_line.h"

char	*get_next_line(int fd);
size_t	ft_arrlen(char **arr);
char	*ft_strdup(const char *src);
char	*ft_stradd(char const *s1, char const *s2);
char	**read_map(char *file);
int		map_checker(char **map);


#endif