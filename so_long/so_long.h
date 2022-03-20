/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:02:32 by sharrach          #+#    #+#             */
/*   Updated: 2022/03/20 19:48:43 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>

# define BUFFER_SIZE 1

#include<stdio.h>
#include<unistd.h>
#include<string.h>

char	*get_next_line(int fd);
static int	ft_read_fd(int fd, char **next_line);



#endif