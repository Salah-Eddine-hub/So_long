/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:12:53 by sharrach          #+#    #+#             */
/*   Updated: 2021/12/09 12:12:55 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

void	check_format(int *count, int i, const char *s, va_list args)
{
	if (s[i] == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (s[i] == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (s[i] == 'd' || s[i] == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (s[i] == 'u')
		ft_putunbr(va_arg(args, unsigned int), count);
	else if (s[i] == 'x')
		ft_hex(va_arg(args, unsigned int), count);
	else if (s[i] == 'X')
		ft_uhex(va_arg(args, unsigned int), count);
	else if (s[i] == 'p')
	{
		ft_putstr("0x", count);
		ft_hex(va_arg(args, unsigned long), count);
	}
	else if (s[i] == '%')
		ft_putchar(s[i], count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i])
				check_format(&count, i, str, args);
		}
		else
			ft_putchar(str[i], &count);
		i ++;
	}
	va_end(args);
	return (count);
}
