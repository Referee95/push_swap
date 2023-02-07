/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:16:55 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/07 19:13:47 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **nodea)
{
	t_list	*t;
	t_list	*s;

	s = *nodea;
	(*nodea) = (*nodea)->next;
	t = (*nodea)->next;
	(*nodea)->next = s;
	s->next = t;
	ft_printf("sa\n");
}

void	sb(t_list **nodeb)
{
	t_list	*t;
	t_list	*s;

	s = *nodeb;
	(*nodeb) = (*nodeb)->next;
	t = (*nodeb)->next;
	(*nodeb)->next = s;
	s->next = t;
	ft_printf("sb\n");
}

void	ss(t_list **nodea, t_list **nodeb)
{
	sa(nodea);
	sb(nodeb);
	ft_printf("ss\n");
}

void	pa(t_list **lst, t_list **node)
{
	t_list	*t;

	if (*node)
		t = *lst;
	else
		t = 0;
	*lst = *node;
	*node = (*node)->next;
	(*lst)->next = t;
	ft_printf("pa\n");
}

void	pb(t_list **lst, t_list **node)
{
	t_list	*t;

	t = *node;
	*node = *lst;
	*lst = (*lst)->next;
	(*node)->next = t;
	ft_printf("pb\n");
}
