/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:38:01 by sharrach          #+#    #+#             */
/*   Updated: 2022/04/15 14:03:45 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	ft_is_rectangular(char **map)
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

static	int	ft_is_map_closed(char **map)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (map[0][x] && map[0][x] == '1'
		&& map[ft_arrlen(map) - 1][x] == '1')
		x ++;
	if (x != ft_strlen(map[0]))
		return (0);
	while (map[y]
		&& map[y][0] == '1'
		&& map[y][ft_strlen(map[0]) - 1] == '1')
		y ++;
	if (y != ft_arrlen(map))
		return (0);
	return (1);
}

static	int	component_check(char **map, char c)
{
	int	y;

	y = 0;
	while (map[y])
	{
		if (ft_strchr(map[y], c))
			return (1);
		y ++;
	}
	return (0);
}

static	int	body_check(char **map)
{
	int	y;
	int	x;
	int	count;

	y = 1;
	count = 0;
	while (map[y])
	{
		x = 1;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				count ++;
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'C'
				&& map[y][x] != 'P' && map[y][x] != 'E')
				return (0);
			x ++;
		}
		y ++;
	}
	if (count != 1)
		return (0);
	return (1);
}

int	map_checker(char **map)
{
	if (ft_is_rectangular(map) && ft_is_map_closed(map)
		&& component_check(map, 'P') <= 1 && component_check(map, 'E')
		&& component_check(map, 'C') && body_check(map))
		return (1);
	return (0);
}
