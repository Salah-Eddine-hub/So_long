/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:55:59 by sharrach          #+#    #+#             */
/*   Updated: 2022/03/21 10:55:52 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_read_fd(int fd, char **next_line)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	int			ret;
	size_t		buffer_len;

	if (buffer[fd][0] == '\0')
	{
		ret = read(fd, buffer[fd], BUFFER_SIZE);
		buffer[fd][ret] = '\0';
		if (ret < 1)
		{
			if (ret == -1)
				ft_bzero(*next_line, 1);
			return (0);
		}
	}
	buffer_len = 0;
	while (buffer[fd][buffer_len] && buffer[fd][buffer_len] != '\n')
		buffer_len ++;
	if (buffer[fd][buffer_len] == '\n')
		buffer_len ++;
	*next_line = ft_strnljoin(*next_line, buffer[fd]);
	ft_strcpy(buffer[fd], &buffer[fd][buffer_len]);
	return (1);
}

char	*get_next_line(int fd)
{
	char	*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_line = malloc (1 * sizeof(char));
	if (!next_line)
		return (0);
	next_line[0] = '\0';
	while (!ft_strchr(next_line, '\n'))
		if (!ft_read_fd(fd, &next_line))
			break ;
	if (next_line[0] == '\0')
	{
		free (next_line);
		return (0);
	}
	return (next_line);
}
