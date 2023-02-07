/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:08:51 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/07 10:05:10 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nbr_w(char *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != c)
				i++;
			n++;
		}
	}
	return (n);
}

int	w_len(char *s, char c)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		y++;
	}
	return (y);
}

void	w_cpy(char *d, char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (p == 0)
		return (0);
	ft_bzero(p, count * size);
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!s)
		return (0);
	str = ft_calloc((nbr_w((char *)s, c) + 1), sizeof(char *));
	if (!str)
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			str[y] = ft_calloc((w_len((char *)&s[i], c) + 1), 1);
			if (!str[y])
				return (0);
			w_cpy(str[y++], (char *)&s[i], c);
			i = i + w_len((char *)&s[i], c);
		}
	}
	return (str);
}
