/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:18:28 by kadam             #+#    #+#             */
/*   Updated: 2024/04/29 20:26:42 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	int				index;
}					t_list;

char				**ft_split(const char *str, const char c);
void				get_free(char **result);
int					ft_atoi_check(const char *str, int *xx, int i,
						long long result);
int					ft_atoi(const char *str);

t_list				*ft_lstnew(int content, int index);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
void				ft_lstclear(t_list **lst);

int					check_args(int ac, char **av, int i, int j);

void				ft_swap(int *a, int *b);
void				sa(t_list **stack_a);
void				sb(t_list **satck_b);
void				ss(t_list **satck_a, t_list **satck_b);
void				ra(t_list **stack_a, int index);
void				rb(t_list **stack_b, int index);
void				rr(t_list **stack_a, t_list **stack_b);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_a, t_list **stack_b);
void				pp(t_list **stack_a, t_list **stack_b);

void				sort2(int size, t_list **stack_a);
void				sort3(t_list **stack_a);
void				sort4(t_list **stack_a, t_list **stack_b);
void				sort5(t_list **stack_a, t_list **stack_b);
void				sort100(t_list **stack_a, t_list **stack_b, t_list *stack_y,
						int end);
void				last_sort(t_list **stack_a, t_list **stack_b, int size);

int					find_min(t_list *stack_a);
int					find_max(t_list *stack_a);
t_list				*sort_tab(t_list *stack_x, int i, int swap);
void				give_index(t_list *stack_a, t_list *stack_y);
int					give_rangs(int max, t_list *stack_b);

void				ft_putstr_fd(char *str, int fd);

#endif