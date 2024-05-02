/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:18:28 by kadam             #+#    #+#             */
/*   Updated: 2024/04/29 20:29:28 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s1);
char				*ft_strchr(char *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*get_next_line(int fd);

char				**ft_split(const char *str, const char c);
void				get_free(char **result);
int					ft_atoi_check(const char *str, int *xx, int i,
						long long result);
int					ft_atoi(const char *str);

t_list				*ft_lstnew(int content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
void				ft_lstclear(t_list **lst);

int					check_args(int ac, char **av, int i, int j);

void				ft_swap(int *a, int *b);

void				sa(t_list **stack_a);
void				sb(t_list **satck_b);
void				ss(t_list **satck_a, t_list **satck_b);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_a, t_list **stack_b);
void				pp(t_list **stack_a, t_list **stack_b);

void				ft_putstr_fd(char *str, int fd);
int					ft_strcmp(char *s1, char *s2);
int					is_sorted(t_list *stack_a);

#endif