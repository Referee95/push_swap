/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:56:14 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/09 17:52:06 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
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

void	check_error(char *s1)
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
	ft_free(str);
	werror(1);
}

// char	*read_line()
// {
// 	char	*s1;
// 	char	*s2;
// 	int		i;
// 	int		j;

// 	s1 = malloc(1);
// 	s1[0] = '\0';
// 	i = 0;
// 	j = 1;
// 	s2 = 0;
// 	while (j > 0 && newline(s2))
// 	{
// 		j = read(0, s1, 1);
// 		i++;
		
// 		s2 = ft_strjoin2(s2, s1);
// 		if (s1[0] == '\0')
// 			return (s2);
	
// 	}
// 	s2[--i] = '\0';
// 	free(s1);
// 	return (s2);
// }
char	*read_line()
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
		if (s1[0] == '\0')
			{
				free(s2);
				return (s1);
			}
	}
	free(s1);
	s2[--i] = '\0';
	return (s2);
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
// int main(int ac, char **av)
// {
//     struct s_main	*x;
//     t_list			*nodea;
// 	t_list			*nodeb;

//     nodeb = 0;
//     char *s1;
// 	errors(av, ac);
//     x = malloc(sizeof(struct s_main));
   
//     x->s = join(ac, &av[1]);
// 	x->str = ft_split(x->s, ' ');
// 	free(x->s);
// 	ac = nbr_arg(x->str);
// 	x->ptr = convert(x->str, ac);
// 	min_max(x->ptr, ac);
// 	fois_2(x->ptr, ac);
// 	if (is_sorted(x->ptr, ac) == 1)
// 		exit(0);
//     x->ptrsort = array_sort(x->ptr, ac);
// 	nodea = array_to_linklist(&x->ptr[0], ac);
	
//     while (1)
//     {
//        s1 = read_line();
//        if (!s1[0])
// 	   {
// 			free(s1);
// 			break ;
// 		}
//        	check_error(s1);
//         algo(s1, &nodea, &nodeb);
// 		free(s1);
//     }
// 	if(check_stack(nodea))
// 		ft_printf("OK\n");
// 	else
// 		ft_printf("KO\n");
// 	free_list(nodea);
// 	free(x->ptrsort);
// 	free(x);
// 	return(0);
// }