/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:48:27 by sharrach          #+#    #+#             */
/*   Updated: 2021/12/18 18:48:28 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *count)
{
	if (nb == -2147483648)
		ft_putstr("-2147483648", count);
	else if (nb < 0)
	{
		ft_putchar('-', count);
		ft_putnbr(nb * -1, count);
	}
	else if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48, count);
	else
	{
		ft_putnbr(nb / 10, count);
		ft_putchar(nb % 10 + 48, count);
	}
}

void	ft_putunbr(unsigned int nb, int *count)
{
	if (nb <= 9)
		ft_putchar(nb + 48, count);
	else
	{
		ft_putnbr(nb / 10, count);
		ft_putchar(nb % 10 + 48, count);
	}
}

void	ft_putstr(char *str, int *count)
{
	int	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], count);
		i++;
	}
}

void	ft_hex(unsigned long x, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (x <= 15)
		ft_putchar(base[x], count);
	else
	{
		ft_hex(x / 16, count);
		ft_hex(x % 16, count);
	}
}

void	ft_uhex(unsigned int x, int *count)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (x <= 15)
		ft_putchar(base[x], count);
	else
	{
		ft_uhex(x / 16, count);
		ft_uhex(x % 16, count);
	}
}
