/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:53:20 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/10 18:24:55 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lindex(t_list **node, int *array, int size)
{
	t_list	*head;
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
	if (ac == 1)
		exit(0);
	errors(av);
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
