/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:35:46 by sharrach          #+#    #+#             */
/*   Updated: 2022/04/13 18:08:11 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_pic(t_data *img)
{
	img->wall = mlx_xpm_file_to_image(img->mlx,
			"img/wall.xpm", &img->img_width, &img->img_height);
	img->img_player = mlx_xpm_file_to_image(img->mlx,
			"img/player1.xpm", &img->img_width, &img->img_height);
	img->bac = mlx_xpm_file_to_image(img->mlx,
			"img/white.xpm", &img->img_width, &img->img_height);
	img->img_exit = mlx_xpm_file_to_image(img->mlx,
			"img/Exit.xpm", &img->img_width, &img->img_height);
	img->img_collect = mlx_xpm_file_to_image(img->mlx,
			"img/Kek.xpm", &img->img_width, &img->img_height);
}

int	main(int argc, char **argv)
{
	t_data	img;
	char	*extension;

	if (argc != 2)
		return (ft_printf("Error\nFew arguments"), EXIT_FAILURE);
	extension = ft_strrchr(argv[1], '.');
	if (!extension || ft_strncmp(extension, ".ber", 5) != 0)
		return (ft_printf("Error\nInvalid map."), EXIT_FAILURE);
	img.map = read_map(argv[1]);
	if (!map_checker(img.map))
		return (ft_printf("Error\nInvalid map."), EXIT_FAILURE);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx,
			50 * ft_strlen(img.map[0]), 50 * ft_arrlen(img.map), "so_long");
	map_pic(&img);
	img.move = 0;
	draw_img(img);
	mlx_hook(img.mlx_win, 2, 1L << 0, key_hook, &img);
	mlx_hook(img.mlx_win, 17, 0, exit_program, &img);
	mlx_loop(img.mlx);
}
