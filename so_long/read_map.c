/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:57:06 by sharrach          #+#    #+#             */
/*   Updated: 2022/04/05 13:19:57 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *file)
{
	int		fd;
	char	*line;
	char	*lines;
	char	**map;
	
	
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit (1);
	lines = ft_strdup("");
	while(1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		lines = ft_stradd(lines, line);
		if (line[0] == '\n')
			exit(EXIT_FAILURE);
		free(line);
	}
	if (lines[0] != '1')
		exit(EXIT_FAILURE);
	close(fd);
	map = ft_split(lines, '\n');
	free(lines);
	return (map);
}
