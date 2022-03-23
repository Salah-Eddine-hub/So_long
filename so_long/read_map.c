/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:57:06 by sharrach          #+#    #+#             */
/*   Updated: 2022/03/23 11:51:35 by sharrach         ###   ########.fr       */
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
		free(line);
	}
	close(fd);
	map = ft_split(lines, '\n');
	free(lines);
	return (map);
}