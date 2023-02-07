/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:25:31 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/07 12:33:36 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	werror(int l)
{
	if (l == 1)
	{
		write(1, "Error\n", 7);
		exit(0);
	}
}

void	fois_2(int *av, int ac)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (av[i] == av[j])
			{
				free(av);
				werror(1);
			}
			j++;
		}
		i++;
	}
}

void	error1(char **av)
{
	int	i;
	int	j;

	i = -1;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j] != '\0')
		{
			if (av[i][j] && !((av[i][j] >= '0' && av[i][j] <= '9')
					|| av[i][j] == ' '))
			{
				if (av[i][j] && ((av[i][j] == '+') || (av[i][j] == '-')))
				{
					if (!(av[i][j + 1] >= '0' && av[i][j + 1] <= '9')
						|| (av[i][j - 1] >= '0' && av[i][j - 1] <= '9'))
						werror(1);
				}
				else if (!((av[i][j + 1] >= '0' && av[i][j + 1] <= '9')
							|| av[i][j + 1] == ' '))
					werror(1);
			}
		}
	}
}

void	error2(char **av)
{
	int	i;
	int	j;
	int	m;
	int	k;

	m = 0;
	i = 0;
	j = 0;
	if (!av[i][j])
		werror(1);
	i = -1;
	while (av[++i])
	{
		j = -1;
		k = 0;
		while (av[i][++j])
		{
			if (av[i][j] == ' ')
				m++;
			else
				k++;
		}
	}
	if (k == 0)
		werror(1);
}

void	errors(char **av, int ac)
{
	if (ac <= 2)
		exit(1);
	error1(&av[1]);
	error2(&av[1]);
}
