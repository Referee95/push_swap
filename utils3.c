/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 08:34:00 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/10 18:23:26 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_max(long long *ptr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ptr[i] < -2147483648)
		{
			free(ptr);
			werror(1);
		}
		if (ptr[i] > 2147483647)
		{
			free(ptr);
			werror(1);
		}
		i++;
	}
}

int	newline(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*problem(char *str)
{
	str = malloc(1);
	str[0] = '\0';
	return (str);
}

char	*ft_strjoin2(char *str, char *str1)
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
	free(str);
	return (src);
}

void	free_ft(t_list *nodea, t_list *nodeb, int *ptr)
{
	if (nodeb)
		free_list(nodeb);
	free_list(nodea);
	free(ptr);
}
