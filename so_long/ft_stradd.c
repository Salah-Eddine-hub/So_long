/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:59:57 by sharrach          #+#    #+#             */
/*   Updated: 2022/03/22 10:34:25 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static	char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;
	int	lendest;
	int	lensrc;
	int	lenofboth;

	i = 0;
	j = 0;
	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	lenofboth = lendest + lensrc;
	while (i < lendest)
		i++;
	while (i < lenofboth)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_stradd(char const *s1, char const *s2)
{
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	s = ((char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s == 0)
		return (NULL);
	ft_strcpy(s, (char *) s1);
	ft_strcat(s, (char *) s2);
	free((void *)s1);
	return (s);
}
