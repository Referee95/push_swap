/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:49:39 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/09 16:28:00 by ykhalil-         ###   ########.fr       */
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
	if (!line)
		return (0);
	while (line[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str, char *str1)
{
	int		i;
	int		j;
	char	*src;

	i = -1;
	j = 0;
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
	free(str);
	return (src);
}

int	is_sorted(long long *ptr, int l)
{
	int	i;

	i = 0;
	while (i < l - 1)
	{
		if (ptr[i] > ptr[i + 1])
			return (0);
		i++;
	}
	free(ptr);
	return (1);
}
int	check_stack(t_list *list)
{
	while (list)
	{
		if(list->next && list->content > list->next->content)
			return(0);
		list = list->next;
	}
	free_list(list);
	return(1);
}

