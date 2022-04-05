/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:35:46 by sharrach          #+#    #+#             */
/*   Updated: 2022/04/05 16:12:29 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
	char	**map;
	void	*img_player;
	void	*img_colect;
	void	*bac;
	int		i;
	int		j;
	void	*mlx;
	void	*mlx_win;
	
}				t_data;

int	main(int argc, char **argv)
{
	t_data	img;
	
	
	(void)argv;
	char	**str = ft_split("Fomo.xpm Alpha.xpm Fud.xpm Kek.xpm", ' ');
	if (argc != 2)
	{
		ft_putendl_fd("Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	img.map = read_map("map.ber");
	if (map_checker(img.map))
		return (1);
	srand(time(0));
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 50 * ft_strlen(img.map[0]), 50 * ft_arrlen(img.map), "so_long");
	img.img = mlx_xpm_file_to_image(img.mlx, "wall.xpm", &img.img_width, &img.img_height);
	img.img_player = mlx_xpm_file_to_image(img.mlx, "player1.xpm", &img.img_width, &img.img_height);
	img.bac = mlx_xpm_file_to_image(img.mlx, "white.xpm", &img.img_width, &img.img_height);
	img.i = 0;
	while (img.map[img.i])
	{
		img.j = 0;
		while (img.map[img.i][img.j])
		{
			mlx_put_image_to_window(img.mlx, img.mlx_win, img.bac, img.j * 50, img.i * 50);
			if (img.map[img.i][img.j] == '1')
				mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, img.j * 50, img.i * 50);
			if (img.map[img.i][img.j] == 'P')
				mlx_put_image_to_window(img.mlx, img.mlx_win, img.img_player, img.j * 50, img.i * 50);
			if (img.map[img.i][img.j] == 'C')
			{
				img.img_colect = mlx_xpm_file_to_image(img.mlx, str[(rand() % (3 - 0 + 1)) + 0], &img.img_width, &img.img_height);
				mlx_put_image_to_window(img.mlx, img.mlx_win, img.img_colect, img.j * 50, img.i * 50);
			}
			img.j++;
		}
		img.i++;
	}
	mlx_loop(img.mlx);
}
