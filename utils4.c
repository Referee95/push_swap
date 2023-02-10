/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:43:52 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/10 18:24:10 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*read_line(void)
{
	char	*s1;
	char	*s2;
	int		i;
	int		j;

	s1 = malloc(2);
	s1[0] = '\0';
	i = 0;
	j = 1;
	s2 = 0;
	while (j > 0 && newline(s2))
	{
		j = read(0, s1, 1);
		s1[j] = '\0';
		i++;
		s2 = ft_strjoin2(s2, s1);
		if (s1[0] == '\0' || s2[0] == '\n')
		{
			free(s2);
			return (s1);
		}
	}
	free(s1);
	s2[--i] = '\0';
	return (s2);
}

void	check_error(char *s1, t_list **nodea, t_list **nodeb, int *ptr)
{
	char	**str;
	int		i;

	str = ft_split("sa sb ss ra rb rr rra rrb rrr pa pb", ' ');
	i = 0;
	while (str[i])
	{
		if (ft_strcmp(s1, str[i]))
		{
			ft_free(str);
			return ;
		}
		i++;
	}
	free(s1);
	ft_free(str);
	free_ft(*nodea, *nodeb, ptr);
	werror(1);
}

void	algo(char *str, t_list **nodea, t_list **nodeb)
{
	if (ft_strcmp(str, "sa") == 1)
		sa(nodea, 0);
	else if (ft_strcmp(str, "sb") == 1)
		sb(nodeb, 0);
	else if (ft_strcmp(str, "ss") == 1)
		ss(nodea, nodeb, 0);
	else if (ft_strcmp(str, "ra") == 1)
		ra(nodea, 0);
	else if (ft_strcmp(str, "rb") == 1)
		rb(nodeb, 0);
	else if (ft_strcmp(str, "rr") == 1)
		rr(nodea, nodeb, 0);
	else if (ft_strcmp(str, "rra") == 1)
		rra(nodea, 0);
	else if (ft_strcmp(str, "rrb") == 1)
		rrb(nodeb, 0);
	else if (ft_strcmp(str, "rrr") == 1)
		rrr(nodea, nodeb, 0);
	else if (ft_strcmp(str, "pa") == 1)
		pa(nodea, nodeb, 0);
	else if (ft_strcmp(str, "pb") == 1)
		pb(nodea, nodeb, 0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
