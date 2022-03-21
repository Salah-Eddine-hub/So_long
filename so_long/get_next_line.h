/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:20:12 by sharrach          #+#    #+#             */
/*   Updated: 2022/03/21 23:23:19 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdlib.h>
# include<stdio.h>
# include<unistd.h>
# include<fcntl.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const	char *str);
void	ft_strcpy(char *dst, const char *src);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
char	*ft_strnljoin(char *s1, char *s2, size_t n);
#endif