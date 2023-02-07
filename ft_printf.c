/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:35:09 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/02 16:10:33 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count(unsigned long n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		i++;
		n /= 16;
	}
	return (i);
}

int	ft_puthxd(unsigned long n, char *str)
{
	int	count;

	count = ft_count(n);
	if (n == 0)
		ft_putchar('0');
	else if (n > 15)
	{
		ft_puthxd(n / 16, str);
		ft_putchar(str[n % 16]);
	}
	else
		ft_putchar(str[n % 16]);
	return (count);
}

static int	type(const char *str, va_list arg)
{
	int	i;

	i = 0;
	if (*str == 'c')
		i = ft_putchar(va_arg(arg, int));
	else if (*str == 's')
		i = ft_putstr(va_arg(arg, char *));
	else if (*str == 'p')
	{
		i = ft_putstr("0x");
		i += ft_puthxd(va_arg(arg, unsigned long), "0123456789abcdef");
	}
	else if (*str == 'd' || *str == 'i')
		i = ft_putnbr(va_arg(arg, int));
	else if (*str == 'u')
		i = ft_putunsigned(va_arg(arg, unsigned int));
	else if (*str == 'x')
		i = ft_puthxd(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (*str == 'X')
		i = ft_puthxd(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (*str == '%')
		i = ft_putchar('%');
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		y;

	va_start(arg, s);
	y = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			y += type(s, arg);
			s++;
		}
		else
		{
			y += ft_putchar(*s);
			s++;
		}
	}
	va_end(arg);
	return (y);
}
