/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:49:39 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/01/25 17:47:47 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = (char)c;
		i++;
	}
	return (str);
}

int	ft_strlen(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

char	*problem(char *str)
{
	str = malloc(1);
	str[0] = '\0';
	return (str);
}

char	*ft_strjoin(char *str, char *str1)
{
	int		i;
	int		j;
	char	*src;

	i = -1;
	j = 0;
	if (!str)
		str = problem(str);
	src = malloc(ft_strlen(str) + ft_strlen(str1) + 1);
	if (!src)
		return (0);
	while (str[++i] != '\0')
		src[i] = str[i];
	while (str1[j] != '\0')
		src[i++] = str1[j++];
	src[i] = '\0';
	if (i == 0)
	{
		free(src);
		free(str);
		return (0);
	}
	src[i] = '\0';
	free(str);
	return (src);
}
