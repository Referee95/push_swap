/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:27:40 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/09 17:39:04 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int cn)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	node->content = cn;
	node->next = NULL;
	return (node);
}

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	case2_5(t_list **nodea, t_list **nodeb, int ac)
{
	if (ac == 2)
		case_2(nodea, ac);
	else if (ac == 3)
		case_3(nodea, ac);
	else if (ac > 3 && ac < 6)
		case_5(nodea, nodeb, ac);
	else if (ac > 5)
		case_100(nodea, nodeb, ac);
	if (*nodea)
		free_list(*nodea);
	if (*nodeb)
		free_list(*nodeb);
}

void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		tmp->next = NULL;
		free(tmp);
	}
}

void	ft_free(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}
