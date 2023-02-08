/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:01:49 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/08 09:50:52 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_line(char *line)
{
	char	*str;
	int		i;
	int		j;

	if (line[0] == 0)
	{
		free(line);
		return (0);
	}
	j = ft_strnlen(line);
	str = malloc(j + 1);
	i = 0;
	while (i < j && line[i] != '\n' && line[i])
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

int	ft_strnlen(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	return (i);
}

int	newline(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i] != '\0' && line[i])
	{
		if (line[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*line_readed(int fd, char *etc)
{
	int		n;
	char	*buf;

	n = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	while (n > 0 && newline(etc))
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
		{
			free(etc);
			free(buf);
			return (0);
		}
		buf[n] = '\0';
		etc = ft_strjoin(etc, buf);
	}
	free(buf);
	return (etc);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*etc;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	line = 0;
	etc = line_readed(fd, etc);
	if (!etc)
		return (0);
	line = ft_line(etc);
	if (!line || !line[0])
		return (0);
	etc = ft_etc(etc);
	return (line);
}
