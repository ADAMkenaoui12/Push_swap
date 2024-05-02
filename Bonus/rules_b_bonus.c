/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:47:33 by kadam             #+#    #+#             */
/*   Updated: 2024/05/01 14:23:26 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sb(t_list **satck_b)
{
	t_list	*temp;
	int		a;
	int		b;

	if (*satck_b == NULL || (*satck_b)->next == NULL || satck_b == NULL)
		return ;
	temp = *satck_b;
	a = temp->content;
	b = temp->next->content;
	ft_swap(&a, &b);
	temp->content = a;
	temp->next->content = b;
}

void	rb(t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b == NULL || (*stack_b)->next == NULL || stack_b == NULL)
		return ;
	temp = *stack_b;
	ft_lstadd_back(stack_b, ft_lstnew(temp->content));
	*stack_b = (*stack_b)->next;
	free(temp);
	temp = NULL;
}

void	rrb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*last_node;

	if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	while (temp->next->next != NULL)
		temp = temp->next;
	last_node = temp->next;
	temp->next = NULL;
	ft_lstadd_front(stack_b, ft_lstnew(last_node->content));
	free(last_node);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_a == NULL || stack_a == NULL)
		return ;
	temp = *stack_a;
	ft_lstadd_front(stack_b, ft_lstnew(temp->content));
	*stack_a = (*stack_a)->next;
	free(temp);
	temp = NULL;
}
