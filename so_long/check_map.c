/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:38:01 by sharrach          #+#    #+#             */
/*   Updated: 2022/03/22 12:57:45 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_is_rectangular(char **map)
{
	int		x;
	size_t	len;
	
	x = 0;
	if (!map[0])
		return (0);
	len = ft_strlen(map[0]);
	while (map[x])
	{
		if (len != ft_strlen(map[x]))
			return (0);
		x ++;
	}
	return (1);
}

int ft_is_map_closed(char **map)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	while(map)
	{
		while(map[0][x] == '1')
			x ++;
		if (x != ft_strlen(map[0]))
			return (0);
		while(map[y][0] == '1')
			y ++;
		if (y != ft_arrlen(map))
			return (0);
		x = 0;
		while(map[ft_arrlen(map) - 1][x] == '1')
			x ++;
		if (x != ft_strlen(map[0]))
			return (0);
		y = 0;
		while(map[y][ft_strlen(map[0]) - 1] == '1')
			y ++;
		if (y != ft_arrlen(map))
			return (0);
	}
	return (1);
}

int	map_checker(char **map)
{
	if (!ft_is_rectangular(map))
		return (0);
	if (!ft_is_map_closed(map))
		return (0);
		
	return (1);
}
