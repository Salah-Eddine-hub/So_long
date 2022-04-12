/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:34:50 by sharrach          #+#    #+#             */
/*   Updated: 2022/04/12 21:12:12 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_program(t_data *img)
{
	int i;
	
	i = 0;
	while(img->map[i])
	{
		free(img->map[i]);
		i ++;
	}
	free (img->map);
	exit (EXIT_SUCCESS);
}
