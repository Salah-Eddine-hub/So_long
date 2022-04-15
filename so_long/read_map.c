/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:57:06 by sharrach          #+#    #+#             */
/*   Updated: 2022/04/14 02:28:49 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	read_map_gnl(int fd, char **lines, char **line)
{
	while (1)
	{
		*line = get_next_line(fd);
		if (!*line)
			break ;
		if ((*line)[0] == '\n')
		{
			ft_printf("Error\nNew Line in Map!\n");
			free(*line);
			free(*lines);
			exit(EXIT_FAILURE);
		}
		*lines = ft_stradd(*lines, *line);
		free(*line);
	}
}

char	**read_map(char *file)
{
	int		fd;
	char	*lines;
	char	*line;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n%s: no such file or directory.\n", file);
		exit(EXIT_FAILURE);
	}
	lines = ft_strdup("");
	line = NULL;
	read_map_gnl(fd, &lines, &line);
	map = ft_split(lines, '\n');
	free(lines);
	close(fd);
	return (map);
}
