/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:53:23 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/08 09:56:03 by ykhalil-         ###   ########.fr       */
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
struct s_main
{
	char			**str;
	long long		*ptr;
	int				*ptrsort;
	char			*s;
};

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char				*ft_line(char *line);
int					ft_strnlen(char *line);
char				*ft_etc(char *line);
char				*ft_strjoin(char *str, char *str1);
char				*get_next_line(int fd);
char				*problem(char *str);
char				*line_readed(int fd, char *etc);
void				ft_bzero(void *s, size_t n);
t_list				*ft_lstnew(int cn);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strjoin(char *str, char *str1);
int					ft_strlen(char *line);
void				*ft_calloc(size_t count, size_t size);
void				sa(t_list **nodea);
void				sb(t_list **nodeb);
void				ss(t_list **nodea, t_list **nodeb);
void				pa(t_list **lst, t_list **node);
void				pb(t_list **lst, t_list **node);
void				ra(t_list **nodea);
void				rb(t_list **nodeb);
void				rr(t_list **nodea, t_list **nodeb);
void				rra(t_list **nodea);
void				rrb(t_list **nodeb);
void				rrr(t_list **nodea, t_list **nodeb);
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
void				error3(char	**av);
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
#endif