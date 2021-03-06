/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesquare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:53:52 by sharrach          #+#    #+#             */
/*   Updated: 2022/03/19 21:40:52 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_program
{
    void    *mlx_pointer;
    void    *window;
}   t_program;

int main(void)
{
    t_program   win;

    win.mlx_pointer = mlx_init();
    win.window = mlx_new_window(win.mlx_pointer, 1080, 720, "Salah");
    int i = 0;
    while (i <= 1000)
    {
        mlx_pixel_put(win.mlx_pointer, win.window, 15, i, 0x0000FF00);
        i++;
    }
    mlx_loop(win.mlx_pointer);
}
