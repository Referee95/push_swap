/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:56:14 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/10 18:21:48 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	norminette(char *s1, t_list **nodea, t_list **nodeb, int *ptr)
{
	while (1)
	{
		s1 = read_line();
		if (!s1[0])
		{
			free(s1);
			break ;
		}
		check_error(s1, nodea, nodeb, ptr);
		algo(s1, nodea, nodeb);
		free(s1);
	}
}

void	check_stack2(int i)
{
	if (i)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	check_stack(t_list *list, t_list *listb)
{
	if (listb)
		return (0);
	while (list)
	{
		if (list->next && list->content > list->next->content)
			return (0);
		list = list->next;
	}
	free_list(list);
	return (1);
}

int	main(int ac, char **av)
{
	t_main	x;
	t_list	*nodea;
	t_list	*nodeb;
	char	*s1;

	s1 = 0;
	nodeb = 0;
	if (ac == 1)
		exit(0);
	errors(av);
	x.s = join(ac, &av[1]);
	x.str = ft_split(x.s, ' ');
	free(x.s);
	ac = nbr_arg(x.str);
	x.ptr = convert(x.str, ac);
	min_max(x.ptr, ac);
	fois_2(x.ptr, ac);
	x.ptrsort = array_sort(x.ptr, ac);
	nodea = array_to_linklist(&x.ptr[0], ac);
	norminette(s1, &nodea, &nodeb, x.ptrsort);
	check_stack2(check_stack(nodea, nodeb));
	free_ft(nodea, nodeb, x.ptrsort);
	return (0);
}
