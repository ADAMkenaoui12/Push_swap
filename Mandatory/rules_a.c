/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:50:44 by kadam             #+#    #+#             */
/*   Updated: 2024/04/04 22:14:01 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a)
{
	t_list	*temp;
	int		a;
	int		b;

	if (*stack_a == NULL || (*stack_a)->next == NULL || stack_a == NULL)
		return ;
	temp = *stack_a;
	a = temp->content;
	b = temp->next->content;
	ft_swap(&a, &b);
	temp->content = a;
	temp->next->content = b;
	ft_putstr_fd("sa\n", 1);
}

void	ra(t_list **stack_a, int index)
{
	t_list	*temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL || stack_a == NULL)
		return ;
	temp = *stack_a;
	ft_lstadd_back(stack_a, ft_lstnew(temp->content, index));
	*stack_a = (*stack_a)->next;
	free(temp);
	temp = NULL;
	ft_putstr_fd("ra\n", 1);
}

void	rra(t_list **stack_a)
{
	t_list	*temp;
	t_list	*last_node;

	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	while (temp->next->next != NULL)
		temp = temp->next;
	last_node = temp->next;
	temp->next = NULL;
	ft_lstadd_front(stack_a, ft_lstnew(last_node->content, last_node->index));
	free(last_node);
	ft_putstr_fd("rra\n", 1);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b == NULL || stack_b == NULL)
		return ;
	temp = *stack_b;
	ft_lstadd_front(stack_a, ft_lstnew(temp->content, 0));
	*stack_b = (*stack_b)->next;
	free(temp);
	temp = NULL;
	ft_putstr_fd("pa\n", 1);
}
