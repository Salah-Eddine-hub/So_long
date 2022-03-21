/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:46:12 by sharrach          #+#    #+#             */
/*   Updated: 2022/03/21 18:29:20 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	i;

	i = ft_strlen(src);
	dest = (char *)malloc((i + 1) * sizeof (char));
	if (dest == NULL)
		return (0);
	ft_strcpy(dest, src);
	return (dest);
}
