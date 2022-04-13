/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:04:53 by sharrach          #+#    #+#             */
/*   Updated: 2022/04/13 18:10:15 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_img(t_data img)
{
	img.y = 0;
	while (img.map[img.y])
	{
		img.x = 0;
		while (img.map[img.y][img.x])
		{
			mlx_put_image_to_window(img.mlx, img.mlx_win,
				img.bac, img.x * 50, img.y * 50);
			if (img.map[img.y][img.x] == '1')
				mlx_put_image_to_window(img.mlx, img.mlx_win,
					img.wall, img.x * 50, img.y * 50);
			if (img.map[img.y][img.x] == 'P')
				mlx_put_image_to_window(img.mlx, img.mlx_win,
					img.img_player, img.x * 50, img.y * 50);
			if (img.map[img.y][img.x] == 'E')
				mlx_put_image_to_window(img.mlx, img.mlx_win,
					img.img_exit, img.x * 50, img.y * 50);
			if (img.map[img.y][img.x] == 'C')
				mlx_put_image_to_window(img.mlx, img.mlx_win,
					img.img_collect, img.x * 50, img.y * 50);
			img.x++;
		}
		img.y++;
	}
}

static	void	player_position(t_data *img)
{
	img->y = 0;
	while (img->map[img->y])
	{
		img->x = 0;
		while (img->map[img->y][img->x])
		{
			if (img->map[img->y][img->x] == 'P')
				return ;
			img->x ++;
		}
		img->y ++;
	}
}

static	size_t	collect_count(t_data *img)
{
	size_t	count;

	count = 0;
	img->y = 0;
	while (img->map[img->y])
	{
		img->x = 0;
		while (img->map[img->y][img->x])
		{
			if (img->map[img->y][img->x] == 'C')
				count ++;
			img->x ++;
		}
		img->y ++;
	}
	return (count);
}

static void	movemment(char *p_one, char *p_two, t_data *img)
{
	if (*p_two == '1')
		return ;
	if (*p_two == 'E' && collect_count(img) > 0)
		return ;
	if (*p_two == 'E' && collect_count(img) == 0)
	{
		ft_printf("You Won");
		exit_program(img);
	}
	else
	{
		*p_one = '0';
		*p_two = 'P';
		draw_img(*img);
		img->move += 1;
		ft_printf ("%d\n", img->move);
	}
}

int	key_hook(int keycode, t_data *img)
{
	player_position(img);
	if (keycode == KEY_A)
		movemment(&img->map[img->y][img->x],
			&img->map[img->y][img->x - 1], img);
	else if (keycode == KEY_D)
		movemment(&img->map[img->y][img->x],
			&img->map[img->y][img->x + 1], img);
	else if (keycode == KEY_S)
		movemment(&img->map[img->y][img->x],
			&img->map[img->y + 1][img->x], img);
	else if (keycode == KEY_W)
		movemment(&img->map[img->y][img->x],
			&img->map[img->y - 1][img->x], img);
	else if (keycode == KEY_ESC)
		exit_program (img);
	return (0);
}
