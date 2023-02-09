/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:43:52 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/09 20:07:57 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	norminette(char *s1, t_list **nodea, t_list **nodeb)
{
	while (1)
	{
		s1 = read_line();
		if (!s1[0])
		{
			free(s1);
			break ;
		}
		check_error(s1);
		algo(s1, nodea, nodeb);
		free(s1);
	}
}

void	check_stack2(t_list *list, int i)
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
