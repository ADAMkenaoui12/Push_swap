/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:58:21 by kadam             #+#    #+#             */
/*   Updated: 2024/03/21 05:54:33 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list *stack_a)
{
	t_list	*ptr;
	int		max;

	ptr = stack_a;
	max = ptr->index;
	while (ptr != NULL)
	{
		if (ptr->index > max)
			max = ptr->index;
		ptr = ptr->next;
	}
	return (max);
}

int	find_min(t_list *stack_a)
{
	t_list	*ptr;
	int		min;

	ptr = stack_a;
	min = ptr->index;
	while (ptr != NULL)
	{
		if (ptr->index < min)
			min = ptr->index;
		ptr = ptr->next;
	}
	return (min);
}

t_list	*sort_tab(t_list *stack_x, int i, int swap)
{
	t_list	*new_node;
	t_list	*ptr;

	new_node = NULL;
	ptr = stack_x;
	while (ptr != NULL && ptr->next != NULL)
	{
		if (ptr->content > ptr->next->content)
		{
			swap = ptr->content;
			ptr->content = ptr->next->content;
			ptr->next->content = swap;
			ptr = stack_x;
		}
		else
			ptr = ptr->next;
	}
	ptr = stack_x;
	while (ptr != NULL)
	{
		ft_lstadd_back(&new_node, ft_lstnew(ptr->content, i));
		i++;
		ptr = ptr->next;
	}
	return (new_node);
}

void	give_index(t_list *stack_a, t_list *stack_y)
{
	t_list	*tmp;

	tmp = stack_a;
	while (stack_y != NULL)
	{
		tmp = stack_a;
		while (tmp != NULL)
		{
			if (stack_y->content == tmp->content)
				tmp->index = stack_y->index;
			tmp = tmp->next;
		}
		stack_y = stack_y->next;
	}
}

int	give_rangs(int max, t_list *stack_b)
{
	int		counter;
	t_list	*ptr;

	ptr = stack_b;
	counter = 0;
	while (ptr != NULL)
	{
		if (ptr->index == max)
			return (counter);
		counter++;
		ptr = ptr->next;
	}
	return (-1);
}
