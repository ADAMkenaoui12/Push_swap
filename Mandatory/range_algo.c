/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:20:35 by kadam             #+#    #+#             */
/*   Updated: 2024/04/17 20:40:58 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_utils(int start, int end, t_list *stack_a)
{
	if (stack_a->index >= start && stack_a->index <= end)
		return (1);
	else if (stack_a->index < start)
		return (2);
	else
		return (0);
}

void	sort100(t_list **stack_a, t_list **stack_b, t_list *stack_y, int end)
{
	t_list	*tmp;
	int		start;

	tmp = *stack_a;
	start = stack_y->index;
	while (tmp != NULL)
	{
		if (sort_utils(start, end, *stack_a) == 1)
		{
			pb(stack_a, stack_b);
			start++;
			end++;
		}
		else if (sort_utils(start, end, *stack_a) == 2)
		{
			pb(stack_a, stack_b);
			rb(stack_b, (*stack_b)->index);
			start++;
			end++;
		}
		else if (sort_utils(start, end, *stack_a) == 0)
			ra(stack_a, (*stack_a)->index);
		tmp = *stack_a;
	}
}

void	last_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	max;
	int	mdl;
	int	x;

	mdl = size / 2;
	while (*stack_b != NULL)
	{
		if (*stack_b != NULL)
		{
			max = find_max(*stack_b);
			x = give_rangs(max, *stack_b);
		}
		if (x == -1)
			break ;
		else if (x == 0)
		{
			pa(stack_a, stack_b);
			size = ft_lstsize(*stack_b);
			mdl = size / 2;
		}
		else if (x > mdl)
			rrb(stack_b);
		else if (x <= mdl)
			rb(stack_b, (*stack_b)->index);
	}
}
