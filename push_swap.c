/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:53:20 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/07 09:05:56 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join(int ac, char **av)
{
	char	*str;
	int		i;

	str = malloc(ac - 1);
	i = 0;
	while (i < ac - 1)
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, av[i]);
		i++;
	}
	return (str);
}

t_list	*array_to_linklist(int *av, int n)
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
	return (head);
}

int	is_sorted(int *ptr, int l)
{
	int	i;

	i = 0;
	while (i < l - 1)
	{
		if (ptr[i] > ptr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	*array_sort(int array[], int size)
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

void	lindex(t_list **node, int array[], int size)
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
}

void	ft_free(char **arr)
{
	int i;

	i = -1;
	while(arr[++i])
		free(arr[i]);
	free(arr);
}

int	main(int ac, char **av)
{
	char **str;
	int *ptr;
	int *ptrsort;
	char *s;
	t_list *nodea;
	t_list *nodeb;
	nodeb = 0;
	
	errors(&av[1], ac);
	s = join(ac, &av[1]);
	str = ft_split(s, ' ');
	ac = nbr_arg(str);
	ptr = convert(&str[0], ac);
	fois_2(&ptr[0], ac);
	if (is_sorted(ptr, ac) == 1)
		exit(1);
	ptrsort = array_sort(ptr, ac);
	nodea = array_to_linklist(&ptr[0], ac);
	lindex(&nodea, &ptrsort[0], ac);
	case2_5(&nodea, &nodeb, ac);
	free(ptr);
	free(s);
	free(ptrsort);
	ft_free(str);
	free_list(nodea);
	free_list(nodeb);
	while (1);
}