/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:17:46 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/09 12:23:52 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **nodea, int i)
{
	t_list	*t;
	t_list	*s;
	t_list	**head;

	if (!*nodea)
		return ;
	head = nodea;
	s = *nodea;
	while (s->next)
		s = s->next;
	s->next = *head;
	t = *head;
	*head = (*head)->next;
	t->next = NULL;
	if (i)
		ft_printf("ra\n");
}

void	rb(t_list **nodeb, int i)
{
	t_list	*t;
	t_list	*s;
	t_list	**head;

	if (!*nodeb)
		return ;
	head = nodeb;
	s = *nodeb;
	while (s->next)
		s = s->next;
	s->next = *head;
	t = *head;
	*head = (*head)->next;
	t->next = NULL;
	if (i)
		ft_printf("rb\n");
}

void	rr(t_list **nodea, t_list **nodeb, int i)
{
	ra(nodea, i);
	rb(nodeb, i);
	if (i)
		ft_printf("rr\n");
}

void	rra(t_list **nodea, int i)
{
	t_list	*s;
	t_list	*t;

	if (!*nodea)
		return ;
	s = *nodea;
	t = *nodea;
	while (s->next)
		s = s->next;
	while (t->next->next)
		t = t->next;
	s->next = *nodea;
	t->next = NULL;
	*nodea = s;
	if (i)
		ft_printf("rra\n");
}

void	rrb(t_list **nodeb, int i)
{
	t_list	*s;
	t_list	*t;

	if (!*nodeb)
		return ;
	s = *nodeb;
	t = *nodeb;
	while (s->next)
		s = s->next;
	while (t->next->next)
		t = t->next;
	s->next = *nodeb;
	t->next = NULL;
	*nodeb = s;
	if (i)
		ft_printf("rrb\n");
}
