/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:08:18 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/09 12:24:53 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(const char *str)
{
	long long	n;
	int			i;
	int			s;

	n = 0;
	i = 0;
	s = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - 48;
		i++;
	}
	return (n * s);
}

long long	*convert(char **str, int size)
{
	long long	*ptr;
	int			j;

	j = 0;
	ptr = malloc(size * sizeof(long long));
	while (str[j])
	{
		ptr[j] = ft_atoi(str[j]);
		j++;
	}
	ft_free(str);
	return (ptr);
}

int	nbr_arg(char **str)
{
	int	i;

	i = 0;
	while (str[i++])
		;
	i = i - 1;
	return (i);
}

void	postion(t_list *node)
{
	t_list	*head;
	int		j;

	j = 0;
	head = node;
	while (head)
	{
		head->postion = j;
		j++;
		head = head->next;
	}
}

void	rrr(t_list **nodea, t_list **nodeb, int i)
{
	rra(nodea, 1);
	rrb(nodeb, 1);
	if (i)
		ft_printf("rrr\n");
}
