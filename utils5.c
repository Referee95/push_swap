/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:13:58 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/10 12:34:11 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

char	*join(int ac, char **av)
{
	char	*str;
	int		i;

	str = malloc(ac - 1);
	str[0] = '\0';
	i = 0;
	while (i < ac - 1)
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, av[i]);
		i++;
	}
	return (str);
}

t_list	*array_to_linklist(long long *av, int n)
{
	t_list	*head;
	t_list	*node;
	t_list	*new_node;
	int		i;

	i = 0;
	node = ft_lstnew(av[i]);
	head = node;
	i++;
	while (i < n)
	{
		new_node = ft_lstnew(av[i]);
		node->next = new_node;
		node = new_node;
		i++;
	}
	free(av);
	return (head);
}

int	*array_sort(long long *array, int size)
{
	int	i;
	int	j;
	int	*array1;

	array1 = malloc(size * sizeof(int));
	i = -1;
	while (++i < size)
		array1[i] = array[i];
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (array1[j] > array1[j + 1])
				ft_swap(&array1[j], &array1[j + 1]);
		}
	}
	return (array1);
}
