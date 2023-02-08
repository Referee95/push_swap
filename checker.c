/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:56:14 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/08 19:50:21 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int ft_strcmp(char *s1, char *s2)
{
    int i;
    
    i = 0;
    while(s1[i] || s2[i])
    {
        if (s1[i] != s2[i])
            return(1);
        i++;
    }
    return(0);
}

void check_error(char **s1)
{   
    char **str;
    str = ft_split("sa sb ss ra rb rr rra rrb rrr pa pb",' ');
    int     i;
    i = 0;
    while(str[i])
    {
        if(!ft_strcmp(*s1, str[i]))
        {
            ft_free(str);
            return ;
       }
      i++;
    }
     ft_free(str);
    werror(1);
}
#include<stdio.h>
char *read_line()
{
    char *s1;
    s1 = malloc(20);
    s1[0] = '\0';
    char *s2;
    int i = 0;
    int j = 1;
    s2 = 0;
    while(j > 0 && newline(s2))
    {
        j = read(0, s1, 1);
        i++;
        s2 = ft_strjoin2(s2, s1);
        if (s1[0] == '\0')
            return (s1);
    }
    s2[--i] = '\0';
    return (s2);
}
int main(int ac, char **av)
{
    struct s_main	*x;
    char *s1;
    x = malloc(sizeof(struct s_main));
    if(ac == 2)
        check_error(&av[1]);
    errors(av, ac);
    x->s = join(ac, &av[1]);
	x->str = ft_split(x->s, ' ');
	ac = nbr_arg(x->str);
	x->ptr = convert(x->str, ac);
    free(x->s);
	min_max(x->ptr, ac);
	fois_2(x->ptr, ac);
	if (is_sorted(x->ptr, ac) == 1)
		exit(0);  
   
    while (1)
    {
       s1 = read_line();
       printf("----%s---", s1);
       if (!s1[0])
        break;
    }
}