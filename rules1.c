/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:16:55 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/09 18:16:59 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **nodea, int i)
{
	t_list	*t;
	t_list	*s;

	if (!*nodea || !(*nodea)->next)
		return ;
	s = *nodea;
	(*nodea) = (*nodea)->next;
	t = (*nodea)->next;
	(*nodea)->next = s;
	s->next = t;
	if (i)
		ft_printf("sa\n");
}

void	sb(t_list **nodeb, int i)
{
	t_list	*t;
	t_list	*s;

	if (!*nodeb || !(*nodeb)->next)
		return ;
	s = *nodeb;
	(*nodeb) = (*nodeb)->next;
	t = (*nodeb)->next;
	(*nodeb)->next = s;
	s->next = t;
	if (i)
		ft_printf("sb\n");
}

void	ss(t_list **nodea, t_list **nodeb, int i)
{
	sa(nodea, i);
	sb(nodeb, i);
	if (i)
		ft_printf("ss\n");
}

void	pa(t_list **lst, t_list **node, int i)
{
	t_list	*t;

	if (!*node)
		return ;
	if (*node)
		t = *lst;
	else
		t = 0;
	*lst = *node;
	*node = (*node)->next;
	(*lst)->next = t;
	if (i)
		ft_printf("pa\n");
}

void	pb(t_list **lst, t_list **node, int i)
{
	t_list	*t;

	if (!*lst)
		return ;
	t = *node;
	*node = *lst;
	*lst = (*lst)->next;
	(*node)->next = t;
	if (i)
		ft_printf("pb\n");
}
