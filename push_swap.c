/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:53:20 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/09 20:23:31 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		j;
	int		i;

	i = 0;
	node = ft_lstnew(av[i]);
	head = node;
	i++;
	j = 0;
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
	int	t;
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

void	lindex(t_list **node, int *array, int size)
{
	t_list	*head;
	int		j;
	int		i;

	i = 0;
	head = *node;
	while (i < size)
	{
		head = *node;
		while (head && (head)->content != array[i])
		{
			head = (head)->next;
		}
		(head)->index = i;
		i++;
	}
	free(array);
}

int	main(int ac, char **av)
{
	t_main	x;
	t_list	*nodea;
	t_list	*nodeb;

	nodeb = 0;
	errors(av, ac);
	x.s = join(ac, &av[1]);
	x.str = ft_split(x.s, ' ');
	free(x.s);
	ac = nbr_arg(x.str);
	x.ptr = convert(&x.str[0], ac);
	min_max(x.ptr, ac);
	fois_2(x.ptr, ac);
	if (is_sorted(x.ptr, ac) == 1)
		exit(0);
	x.ptrsort = array_sort(&x.ptr[0], ac);
	nodea = array_to_linklist(&x.ptr[0], ac);
	lindex(&nodea, &x.ptrsort[0], ac);
	case2_5(&nodea, &nodeb, ac);
}
