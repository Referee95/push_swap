/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_cases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:00:39 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/06 15:13:47 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_2(t_list **node, int i)
{
	if ((*node)->content > (*node)->next->content)
		sa(&(*node));
}

void	case_3(t_list **node, int i)
{
	t_list	*s;
	t_list	*l;

	s = (*node)->next;
	l = (*node)->next->next;
	if ((*node)->content > s->content && s->content < l->content
		&& l->content > (*node)->content)
		sa(&(*node));
	else if ((*node)->content > s->content && s->content > l->content)
	{
		sa(&(*node));
		rra(&(*node));
	}
	else if ((*node)->content > s->content && (*node)->content > l->content
		&& s->content < l->content)
		ra(&(*node));
	else if ((*node)->content < s->content && (*node)->content < l->content
		&& s->content > l->content)
	{
		sa(&(*node));
		ra(&(*node));
	}
	else if (!((*node)->content < s->content && s->content < l->content))
		rra(&(*node));
}

void	case_5(t_list **lista, t_list **listb, int size)
{
	t_list	*head;
	int		i;

	i = 0;
	head = *lista;
	while (size - 3)
	{
		head = *lista;
		while (head->next)
			head = head->next;
		if (head->index == i)
			rra(lista);
		else
		{
			while ((*lista)->index != i)
				ra(lista);
		}
		pb(lista, listb);
		i++;
		size--;
	}
	case_3(lista, size);
	while (*listb)
		pa(lista, listb);
}

void	trier_stack(t_list **lista, t_list **listb, int size)
{
	t_list	*head;

	size = size - 1;
	while (*listb)
	{
		head = *listb;
		postion(head);
		while (head->index != size)
			head = head->next;
		if (head->postion <= size / 2)
		{
			while ((*listb)->index != size)
				rb(listb);
		}
		else if (head->postion > size / 2)
		{
			while ((*listb)->index != size)
				rrb(listb);
		}
		pa(lista, listb);
		size--;
	}
}

void	case_100(t_list **lista, t_list **listb, int size)
{
	int		i;
	int		range;

	i = 0;
	range = 15;
	if (size > 100)
		range = 35;
	while (*lista)
	{
		if ((*lista)->index <= i && i > 0)
		{
			pb(lista, listb);
			rb(listb);
			i++;
		}
		else if ((*lista)->index <= range + i)
		{
			pb(lista, listb);
			i++;
		}
		else
			ra(lista);
	}
	trier_stack(lista, listb, size);
}
