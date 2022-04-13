/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:57:06 by sharrach          #+#    #+#             */
/*   Updated: 2022/04/13 18:07:13 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *file)
{
	t_data	read_map;

	read_map.fd = open(file, O_RDONLY);
	if (read_map.fd == -1)
		exit (1);
	read_map.lines = ft_strdup("");
	while (1)
	{
		read_map.line = get_next_line(read_map.fd);
		if (!read_map.line)
			break ;
		if (read_map.line[0] == '\n')
		{
			ft_printf("Error\nNew Line in Map!\n");
			free(read_map.line);
			free(read_map.lines);
			exit(EXIT_FAILURE);
		}
		read_map.lines = ft_stradd(read_map.lines, read_map.line);
		free(read_map.line);
	}
	read_map.map = ft_split(read_map.lines, '\n');
	return (close(read_map.fd), free(read_map.lines), read_map.map);
}
