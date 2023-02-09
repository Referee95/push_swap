/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:53:23 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/09 20:08:32 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				postion;
	struct s_list	*next;

}					t_list;

typedef struct s_main
{
	char			**str;
	long long		*ptr;
	int				*ptrsort;
	char			*s;
}					t_main;

char				*ft_strjoin2(char *str, char *str1);
char				*problem(char *str);
void				ft_bzero(void *s, size_t n);
t_list				*ft_lstnew(int cn);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strjoin(char *str, char *str1);
int					ft_strlen(char *line);
void				*ft_calloc(size_t count, size_t size);
void				sa(t_list **nodea, int i);
void				sb(t_list **nodeb, int i);
void				ss(t_list **nodea, t_list **nodeb, int i);
void				pa(t_list **lst, t_list **node, int i);
void				pb(t_list **lst, t_list **node, int i);
void				ra(t_list **nodea, int i);
void				rb(t_list **nodeb, int i);
void				rr(t_list **nodea, t_list **nodeb, int i);
void				rra(t_list **nodea, int i);
void				rrb(t_list **nodeb, int i);
void				rrr(t_list **nodea, t_list **nodeb, int i);
char				**ft_split(char const *s, char c);
long long			ft_atoi(const char *str);
int					ft_putchar(char c);
int					ft_puthxd(unsigned long n, char *str);
int					ft_putnbr(long int n);
int					ft_putstr(char *s);
int					ft_putunsigned(unsigned int n);
int					ft_printf(const char *s, ...);
void				case_2(t_list **node, int i);
void				case_3(t_list **node, int i);
void				case_5(t_list **lista, t_list **listb, int i);
void				lindex(t_list **node, int array[], int size);
void				werror(int l);
void				fois_2(long long *av, int ac);
void				error1(char **av);
void				error2(char **av);
void				error3(char **av);
void				errors(char **av, int ac);
long long			*convert(char **str, int size);
int					nbr_arg(char **str);
void				case2_5(t_list **nodea, t_list **nodeb, int ac);
void				ft_swap(int *a, int *b);
void				postion(t_list *node);
void				case_100(t_list **lista, t_list **listb, int size);
void				trier_stack(t_list **lista, t_list **listb, int size);
void				free_list(t_list *list);
void				ft_free(char **arr);
int					is_sorted(long long *ptr, int l);
t_list				*array_to_linklist(long long *av, int n);
void				min_max(long long *ptr, int size);
char				*join(int ac, char **av);
int					newline(char *line);
int					*array_sort(long long *array, int size);
int					check_stack(t_list *list, t_list *listb);
void				check_stack2(t_list *list, int i);
void				free_ft(t_list *nodea, t_list *nodeb, int *ptr, t_main *x);
void				norminette(char *s1, t_list **nodea, t_list **nodeb);
char				*read_line(void);
void				algo(char *str, t_list **nodea, t_list **nodeb);
void				check_error(char *s1);
int					ft_strcmp(char *s1, char *s2);
#endif