/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:35:46 by sharrach          #+#    #+#             */
/*   Updated: 2022/04/02 13:52:17 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	d_data{
	int img_width;
	int img_height;
	char **map;

}	s_truct;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	main(void)
{
	s_truct	pic;
	t_data	img;
	char	*relative_path = "1.xpm";
	void	*mlx;
	void	*mlx_win;

	pic.map = read_map("map.ber");
	if (map_checker(pic.map))
		return (1);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 50 * ft_strlen(pic.map[0]), 50 * ft_arrlen(pic.map), "so_long");
	img.img = mlx_xpm_file_to_image(mlx, relative_path, &pic.img_width, &pic.img_height);
	
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
