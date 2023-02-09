/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:46:20 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/07 19:12:45 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_count(long int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_putnbr(long int n)
{
	int	count;

	count = ft_count(n);
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
	else
	{
		ft_putchar(n + 48);
	}
	return (count);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putunsigned(unsigned int n)
{
	int	i;

	i = 0;
	i += ft_putnbr(n);
	return (i);
}
