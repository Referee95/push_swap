/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:08:18 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/02 17:25:14 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	n;
	int	i;
	int	s;

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

int	*convert(char **str, int size)
{
	int	*ptr;
	int	j;

	j = 0;
	ptr = ft_calloc(size, sizeof(int));
	while (str[j])
	{
		ptr[j] = ft_atoi(str[j]);
		j++;
	}
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

void	rrr(t_list **nodea, t_list **nodeb)
{
	rra(nodea);
	rrb(nodeb);
	ft_printf("rrr\n");
}
