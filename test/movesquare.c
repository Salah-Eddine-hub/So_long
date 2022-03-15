/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesquare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:53:52 by sharrach          #+#    #+#             */
/*   Updated: 2022/03/15 17:06:45 by sharrach         ###   ########.fr       */
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
    mlx_loop(win.mlx_pointer);
    
}


