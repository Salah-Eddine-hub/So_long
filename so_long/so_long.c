/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:35:46 by sharrach          #+#    #+#             */
/*   Updated: 2022/04/10 14:22:52 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct	s_data {
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
	char	**map;
	void	*wall;
	void	*bac;
	void	*img_player;
	void	*img_colect;
	void	*img_exit;
	int		x;
	int		y;
	void	*mlx;
	void	*mlx_win;
	
}				t_data;

void	draw_img(t_data img)
{
	img.x = 0;
	while (img.map[img.x])
	{
		img.y = 0;
		while (img.map[img.x][img.y])
		{
			mlx_put_image_to_window(img.mlx, img.mlx_win, img.bac, img.y * 50, img.x * 50);
			if (img.map[img.x][img.y] == '1')
				mlx_put_image_to_window(img.mlx, img.mlx_win, img.wall, img.y * 50, img.x * 50);
			if (img.map[img.x][img.y] == 'P')
				mlx_put_image_to_window(img.mlx, img.mlx_win, img.img_player, img.y * 50, img.x * 50);
			if (img.map[img.x][img.y] == 'E')
				mlx_put_image_to_window(img.mlx, img.mlx_win, img.img_exit, img.y * 50, img.x * 50);
			if (img.map[img.x][img.y] == 'C')
				mlx_put_image_to_window(img.mlx, img.mlx_win, img.img_colect, img.y * 50, img.x * 50);
			img.y++;
		}
		img.x++;
	}
}

void	move_left(t_data *img)
{
	img->x = 0;
	img->y = 0;
	
	while (img->map[img->x])
	{
		img->y = 0;
		while (img->map[img->x][img->y])
		{
			if (img->map[img->x][img->y - 1] != '1' && img->map[img->x][img->y] == 'P')
			{
				img->map[img->x][img->y - 1] = 'P';
				img->map[img->x][img->y] = '0';
				draw_img(*img);
				return ;
			}
			img->y++;
		}
		img->x++;
	}
}

void	move_right(t_data *img)
{
	img->x = 0;
	img->y = 0;
	
	while (img->map[img->x])
	{
		img->y = 0;
		while (img->map[img->x][img->y])
		{
			if (img->map[img->x][img->y + 1] != '1' && img->map[img->x][img->y] == 'P')
			{
				img->map[img->x][img->y + 1] = 'P';
				img->map[img->x][img->y] = '0';
				draw_img(*img);
				return ;
			}
			img->y++;
		}
		img->x++;
	}
}

void	move_up(t_data *img)
{
	img->x = 1;
	
	while (img->map[img->x])
	{
		img->y = 0;
		while (img->map[img->x][img->y])
		{
			if (img->map[img->x - 1][img->y] != '1' && img->map[img->x][img->y] == 'P')
			{
				img->map[img->x - 1][img->y] = 'P';
				img->map[img->x][img->y] = '0';
				draw_img(*img);
				return ;
			}
			img->y++;
		}
		img->x++;
	}
}

void	move_down(t_data *img)
{
	img->x = 0;
	
	while (img->map[img->x])
	{
		img->y = 0;
		while (img->map[img->x][img->y])
		{
			if (img->map[img->x + 1][img->y] != '1' && img->map[img->x][img->y] == 'P')
			{
				// img->map[img->x + 1][img->y] = 'P';
				// img->map[img->x][img->y] = '0';
				draw_img(*img);
				return ;
			}
			img->y++;
		}
		img->x++;
	}
}

int	key_hook(int keycode, t_data *img)
{
	(void)img;
	if(keycode == KEY_A)
		move_left(img);
	else if(keycode == KEY_D)
		move_right(img);
	else if(keycode == KEY_S)
		move_down(img);
	else if(keycode == KEY_W)
		move_up(img);
	return (0);
}


int	main(int argc, char **argv)
{
	t_data	img;
	
	(void)argv;
	if (argc != 2)
		return (EXIT_FAILURE);
	img.map = read_map(argv[1]);
	if (map_checker(img.map))
		return (1);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 50 * ft_strlen(img.map[0]), 50 * ft_arrlen(img.map), "so_long");
	img.wall = mlx_xpm_file_to_image(img.mlx, "img/wall.xpm", &img.img_width, &img.img_height);
	img.img_player = mlx_xpm_file_to_image(img.mlx, "img/player1.xpm", &img.img_width, &img.img_height);
	img.bac = mlx_xpm_file_to_image(img.mlx, "img/white.xpm", &img.img_width, &img.img_height);
	img.img_exit = mlx_xpm_file_to_image(img.mlx, "img/Exit.xpm", &img.img_width, &img.img_height);
	img.img_colect = mlx_xpm_file_to_image(img.mlx, "img/Kek.xpm", &img.img_width, &img.img_height);
	draw_img(img);
	mlx_key_hook(img.mlx_win, key_hook, &img);
	mlx_loop(img.mlx);
}
